#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "findAscendingColumns.h"
#include "getMinSumOfDiagonal.h"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 4)
    {
      throw std::invalid_argument("Error: Invalid arguments");
    }
    std::ifstream inFile(argv[2]);
    if (!inFile.is_open())
    {
      throw std::runtime_error("Error: Input file could not be opened");
    }
    std::ofstream outFile(argv[3]);
    if (!outFile.is_open())
    {
      throw std::runtime_error("Error: Output file could not be opened");
    }
    size_t rows = 0;
    size_t cols = 0;
    inFile >> rows >> cols;
    if (!inFile)
    {
        throw std::runtime_error("Error: File read error");
    }
    if (rows * cols > 1000)
    {
        throw std::invalid_argument("Error: Array too large");
    }
    int *arr = new int[rows * cols]; // dynamically allocate memory for arr
    if (std::strcmp(argv[1], "1") == 0)
    {
        for (unsigned i = 0; i < rows * cols; i++)
        {
            if (!(inFile >> arr[i]))
            {
                delete[] arr; // free the memory allocated for arr
                throw std::runtime_error("Error: File read error");
            }
        }
        outFile << countGrowingCols(arr, rows, cols) << "\n";
    }
    else if (std::strcmp(argv[1], "2") == 0)
    {
        for (unsigned i = 0; i < rows * cols; i++)
        {
            if (!(inFile >> arr[i]))
            {
                delete[] arr; // free the memory allocated for arr
                throw std::runtime_error("Error: File read error");
            }
        }
        if (rows == 0 || cols == 0)
        {
            delete[] arr; // free the memory allocated for arr
            return 0;
        }
        outFile << calcMinSummSecondaryDiagonal(arr, rows, cols) << "\n";
    }
    else if (std::strcmp(argv[1], "3") == 0)
    {
        char arr[1000];
        for (unsigned i = 0; i < rows * cols; i++)
        {
            if (!(inFile >> arr[i]))
            {
                throw std::runtime_error("Error: File read error");
            }
        }
    }
    else
    {
        delete[] arr; // free the memory allocated for arr
        throw std::invalid_argument("Error: Invalid argument");
    }
    delete[] arr; // free the memory allocated for arr
    if (!outFile)
    {
        throw std::runtime_error("Error: File write error");
    }
  }
  catch (const std::exception & ex)
  {
    std::cout << ex.what() << std::endl;
    return 1;
  }
  return 0;
}

