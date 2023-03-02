#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "countColumnsWithAscElements.h"
#include "countDiagonalsWithoutZero.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Check parameters";
    return 1;
  }

  size_t rows = 0;
  size_t columns = 0;
  std::ifstream inp_file(argv[2]);
  inp_file >> rows >> columns;
  if (!inp_file.is_open())
  {
    std::cout << "Error. File not open" << '\n';
    return 1;
  }
  std::ofstream out_file(argv[3]);
  if (!out_file.is_open())
  {
    std::cout << "error output file could not be opened\n";
    return 1;
  }
  if (rows * columns > 1000)
  {
    std::cout << "Error. Too much data" << '\n';
    return 1;
  }
  if (rows == 0 && columns == 0)
  {
    std::cout << "Error. Matrix is empty" << '\n';
    return 1;
  }
  if (!strcmp(argv[1], "1"))
  {
    int matrix[1000];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        inp_file >> matrix[rows * i + j];
        if (!inp_file)
        {
          std::cout << "Error. File not open";
          return 1;
        }
      }
    }
    std::ofstream out_file(argv[3]);
    size_t result = countColumnsWithAscElements(matrix, rows, columns);
    out_file << "Columns: " << result << "\n";
    if (!out_file)
    {
      std::cout << "Error. Number write error";
      return 1;
    }
  }
  else if (!strcmp(argv[1], "2"))
  {
    int** matrix2 = new int* [rows * columns];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        inp_file >> matrix2[i][j];
        if (!inp_file)
        {
          std::cout << "Error. File not open";
          delete[] matrix2;
          return 1;
        }
      }
    }
    std::ofstream out_file(argv[3]);
    out_file << "Diagonals: " << countDiagonalsWithoutZero(matrix2, rows) << "\n";
    if (!out_file)
    {
      std::cout << "Error. Number write error";
      return 1;
    }
    delete[] matrix2;
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }
  return 0;
}
