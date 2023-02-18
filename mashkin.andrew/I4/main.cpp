#include "repeatElemInCols.h"
#include "findMaxSumOfDiagonal.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Error!";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    std::ifstream inpFile;
    inpFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inpFile.open(argv[2]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    int stMatrix[1000];
    size_t rows = 0, cols = 0;
    try
    {
      inpFile >> rows;
      inpFile >> cols;
    }
    catch (const std::exception& ex)
    {
      inpFile.close();
      std::cout << ex.what() << "\n";
      return 1;
    }
    if (rows * cols > 1000)
    {
      inpFile.close();
      std::cout << rows * cols << " > " << 1000 << "\n";
      return 1;
    }
    try
    {
      for (size_t i = 0; i < rows; i++)
      {
        for (size_t j = 0; j < cols; j++)
        {
          inpFile >> stMatrix[rows * i + j];
        }
      }
    }
    catch (const std::exception& ex)
    {
      inpFile.close();
      std::cout << ex.what() << "\n";
      return 1;
    }
    inpFile.close();
    std::ofstream outFile;
    outFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
      outFile.open(argv[3]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    outFile << repeatElemInCols(stMatrix, rows, cols) << "\n";
    outFile << findMaxSumOfDiagonal(stMatrix, rows, cols) << "\n";
    outFile.close();
    return 0;
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    std::ifstream inpFile;
    inpFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inpFile.open(argv[2]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    size_t rows = 0, cols = 0;
    int* dynMatrix = nullptr;
    try
    {
      inpFile >> rows;
      inpFile >> cols;
      dynMatrix = new int[rows * cols];
      for (size_t i = 0; i < rows; i++)
      {
        for (size_t j = 0; j < cols; j++)
        {
          inpFile >> dynMatrix[rows * i + j];
        }
      }
    }
    catch (const std::exception& ex)
    {
      delete[] dynMatrix;
      inpFile.close();
      std::cout << ex.what() << "\n";
      return 1;
    }
    inpFile.close();
    std::ofstream outFile;
    outFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
      outFile.open(argv[3]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    outFile << repeatElemInCols(dynMatrix, rows, cols) << "\n";
    outFile << findMaxSumOfDiagonal(dynMatrix, rows, cols) << "\n";
    outFile.close();
    delete[] dynMatrix;
    return 0;
  }
  else
  {
    std::cout << "Incorect arg " << argv[1] << "\n";
    return 1;
  }
}
