#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "readMatrix.h"
#include "findLongestSeries.h"
#include "countRowsWithEqualSum.h"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Usage: " << argv[0] << " <input_mode> <input_file> <output_file>\n";
    return 1;
  }
  std::ifstream inputFile;
  inputFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  try
  {
    inputFile.open(argv[2]);
    size_t numRows = 0, numCols = 0;
    int* matrix = nullptr;
    bool useMatrix = std::strcmp(argv[1], "1") == 0;
    if (useMatrix)
    {
      int staticMatrix[1000];
      try
      {
        inputFile >> numRows >> numCols;
        if (numRows * numCols > 1000)
        {
          inputFile.close();
          std::cout << numRows * numCols << " > " << 1000 << "\n";
          return 1;
        }
        readMatrix(inputFile, staticMatrix, numRows, numCols);
        matrix = staticMatrix;
      }
      catch (const std::exception& e)
      {
        inputFile.close();
        std::cout << e.what() << "\n";
        return 1;
      }
    }
    else
    {
      try
      {
        inputFile >> numRows >> numCols;
        if (numRows <= 0 || numCols <= 0)
        {
          std::cout << "Error: matrix dimensions are invalid\n";
          return 1;
        }
        matrix = new int[numRows * numCols];
        readMatrix(inputFile, matrix, numRows, numCols);
      }
      catch (const std::exception& e)
      {
        inputFile.close();
        std::cout << e.what() << "\n";
        delete[] matrix;
        return 1;
      }
    }
    inputFile.close();
    std::ofstream outputFile;
    outputFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
      outputFile.open(argv[3]);
    }
    catch (const std::exception& e)
    {
      std::cout << "Error: Failed to open output file!\n";
      delete[] matrix;
      return 1;
    }
    outputFile << countRowsWithEqualSum(matrix, numRows, numCols) << "\n";
    outputFile << findLongestSeries(matrix, numRows, numCols) << "\n";
    outputFile.close();
    if (!useMatrix)
    {
      delete[] matrix;
    }

    return 0;
  }
  catch (const std::exception& e)
  {
    std::cout << "Error: Failed to read input file!\n";
    return 1;
  }
}
