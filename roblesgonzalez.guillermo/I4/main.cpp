#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "findAscendingColumns.h"
#include "getMinSumOfDiagonal.h"

int readArray(int *arr, size_t rows, size_t cols, std::ifstream& inFile)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(inFile >> arr[i])) {
      std::cout << "Error: Failed to read array element at index " << i << "\n";
      return 1;
    }
  }
  return 0;
}
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Error: Invalid arguments" << "\n";
    return 1;
  }
  std::ifstream inFile(argv[2]);
  if (!inFile)
  {
    std::cout << "Error: Failed to open input file" << "\n";
    return 1;
  }
  std::ofstream outFile(argv[3]);
  if (!outFile)
  {
    std::cout << "Error: Failed to open output file" << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  if (!(inFile >> rows >> cols))
  {
    std::cout << "Error: Failed to read array dimensions" << "\n";
    return 1;
  }
  if (rows * cols > 1000)
  {
    std::cout << "Error: Array too large" << "\n";
    return 1;
  }
  int *arr = new int[rows * cols];
  if (std::strcmp(argv[1], "1") == 0)
  {
    readArray(arr, rows, cols, inFile);
    outFile << countGrowingCols(arr, rows, cols) << "\n";
  }
  else if (std::strcmp(argv[1], "2") == 0)
  {
    readArray(arr, rows, cols, inFile);
    if (rows == 0 || cols == 0)
    {
      delete[] arr;
      return 0;
    }
    outFile << calcMinSummSecondaryDiagonal(arr, rows, cols) << "\n";
  }
  else if (std::strcmp(argv[1], "3") == 0)
  {
    char arr[1000];
    for (size_t i = 0; i < rows * cols; i++)
    {
      if (!(inFile >> arr[i]))
      {
        std::cout << "Error: Failed to read character array element at index " << i << "\n";
        return 1;
      }
    }
    outFile << arr << "\n";
  }
  else
  {
    std::cout << "Error: Invalid argument" << "\n";
    delete[] arr;
    return 1;
  }
  delete[] arr;
  return 0;
}
