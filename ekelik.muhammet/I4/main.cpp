#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "findLongestSeries.h"
#include "countRowsWithEqualSum.h"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Error!";
    return 1;
  }
  
  std::ifstream inputFile;
  inputFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  
  try
  {
    inputFile.open(argv[2]);

    size_t numRows = 0, numCols = 0;
    int* matrix = nullptr;
    bool use_static_matrix = std::strcmp(argv[1], "1") == 0;

    if (use_static_matrix)
    {
      int staticMatrix[1000];
      inputFile >> numRows >> numCols;

      if (numRows * numCols > 1000)
      {
        inputFile.close();
        std::cout << numRows * numCols << " > " << 1000 << "\n";
        return 1;
      }

      for (size_t i = 0; i < numRows; i++)
      {
        for (size_t j = 0; j < numCols; j++)
        {
          inputFile >> staticMatrix[numRows * i + j];
        }
      }

      matrix = staticMatrix;
    }
    else
    {
      inputFile >> numRows >> numCols;
      matrix = new int[numRows * numCols];

      for (size_t i = 0; i < numRows; i++)
      {
        for (size_t j = 0; j < numCols; j++)
        {
          inputFile >> matrix[numRows * i + j];
        }
      }
    }

    inputFile.close();

    std::ofstream outputFile;
    outputFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    outputFile.open(argv[3]);

    outputFile << countRowsWithEqualSum(matrix, numRows, numCols) << "\n";
    outputFile << findLongestSeries(matrix, numRows, numCols) << "\n";
    outputFile.close();

    if (!use_static_matrix) delete[] matrix;

    return 0;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
}
