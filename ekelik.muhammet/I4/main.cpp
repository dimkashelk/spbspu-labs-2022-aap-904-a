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
    std::cout << "Error!";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    std::ifstream inputFile;
    inputFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inputFile.open(argv[2]);
    }
    catch (const std::exception& e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }
    int staticMatrix[1000];
    size_t numRows = 0, numCols = 0;
    try
    {
      inputFile >> numRows >> numCols;
      if (numRows == 0 || numCols == 0 || numRows * numCols > 1000)
      {
        inputFile.close();
        std::cout << "Error: Invalid matrix dimensions!\n";
        return 1;
      }
      readMatrix(inputFile, staticMatrix, numRows, numCols);
    }
    catch (const std::exception& e)
    {
      inputFile.close();
      std::cout << e.what() << "\n";
      return 1;
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
      std::cout << e.what() << "\n";
      return 1;
    }
    outputFile << countRowsWithEqualSum(staticMatrix, numRows, numCols) << "\n";
    outputFile << findLongestSeries(staticMatrix, numRows, numCols) << "\n";
    outputFile.close();
    return 0;
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    std::ifstream inputFile;
    inputFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inputFile.open(argv[2]);
    }
    catch (const std::exception& e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }
    size_t numRows = 0, numCols = 0;
    int* dynamicMatrix = nullptr;
    try
    {
      inputFile >> numRows >> numCols;
      if (numRows == 0 || numCols == 0 || numRows * numCols > 1000)
      {
        inputFile.close();
        std::cout << "Error: Invalid matrix dimensions!\n";
        return 1;
      }
      dynamicMatrix = new int[numRows * numCols];
      readMatrix(inputFile, dynamicMatrix, numRows, numCols);
    }
    catch (const std::exception& e)
    {
      delete[] dynamicMatrix;
      inputFile.close();
      std::cout << e.what() << "\n";
      return 1;
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
      delete[] dynamicMatrix;
      std::cout << e.what() << "\n";
      return 1;
    }
    outputFile << countRowsWithEqualSum(dynamicMatrix, numRows, numCols) << "\n";
    outputFile << findLongestSeries(dynamicMatrix, numRows, numCols) << "\n";
    outputFile.close();
    delete[] dynamicMatrix;
    return 0;
  }
  else
  {
    std::cout << "Error!";
    return 1;
  }
}
