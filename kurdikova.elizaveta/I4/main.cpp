#include <iostream>
#include <cstring>
#include "PositiveRows.h"
#include "ReadMatrix.h"
#include "MinDiagonalSum.h"

int main(int argc, char* argv[])
  {
    // Checking command line input arguments
    if (argc != 4)
    {
      std::cerr << "Error! Invalid number of arguments";
      return 1;
    }
    const char* taskNumber = argv[1];
    if (std::strcmp(taskNumber, "1") && std::strcmp(taskNumber, "2"))
    {
      std::cerr << "Error! Invalid task number. The task number must be 1 or 2";
      return 2;
    }

    std::ifstream inputFile(argv[2]);
    std::ofstream outputFile(argv[3]);
    if (!inputFile.is_open())
    {
      std::cerr << "Error! The input file cannot be opened";
      return 3;
    }
    else if (!outputFile.is_open())
    {
      std::cerr << "Error! The output file cannot be opened";
      return 4;
    }

    size_t rows = 0;
    size_t columns = 0;
    inputFile >> rows >> columns;
    if (!inputFile)
    {
      std::cerr << "Error! An error occurred when reading the size of the matrix";
      return 5;
    }
    if (rows * columns > 1000)
    {
      std::cerr << "Error! The size of the matrix exceeds 1000 elements";
      return 6;
    }

    // Starting tasks
    if (!std::strcmp(taskNumber, "1"))
    {
      int matrix[1000];
      try
      {
        readMatrixFromFile(matrix, rows, columns, inputFile);
      }
      catch (const std::runtime_error& e)
      {
        std::cerr << e.what() << "\n";
        return 7;
      }
      size_t result = getPosRowsCount(matrix, rows, columns);
      outputFile << result << "\n";
      std::cout << result;
      if (!outputFile)
      {
        std::cerr << "Error! An error occurred when writing the result to the output file";
        return 8;
      }
    }
    else
    {
      if (rows != columns || rows == 0)
      {
        std::cerr << "Error! The specified dimensions of the matrix do not correspond to the square matrix";
        return 9;
      }
      int* matrix = nullptr;
      try
      {
        matrix = new int[rows * columns];
        matrix = readMatrixFromFile(matrix, rows, columns, inputFile);
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        delete[] matrix;
        return 7;
      }
      size_t result = minDiagonalSumParallelToSecondary(matrix, rows);
      outputFile << minDiagonalSumParallelToSecondary(matrix, rows) << "\n";
      std::cout << result;
      if (!outputFile)
      {
        std::cerr << "Error! An error occurred when writing the result to the output file";
        delete[] matrix;
        return 8;
      }
      delete[] matrix;
    }
    inputFile.close();
    outputFile.close();
    return 0;
  }

