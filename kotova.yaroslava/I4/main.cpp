#include <iostream>
#include <cstring>
#include <fstream>
#include <cstddef>
#include "columns_w_positive_el.h"
#include "columns_w_unique_el.h"
int main(int argc, char* argv[])
{
  size_t column = 0;
  size_t line = 0;
  if (argc != 4)
  {
    std::cout << "Error...";
    return 1;
  }
  std::ifstream file_matrix_in(argv[2]);
  file_matrix_in >> column;
  file_matrix_in >> line;
  if (!file_matrix_in.is_open())
  {
    std::cout << "file opens with an error";
    return 1;
  }
  if (!file_matrix_in)
  {
    std::cout << "Error...";
    return 1;
  }
  if (column * line > 1000)
  {
    std::cout << "too much parameters for matrix";
    return 1;
  }
  std::ofstream file_matrix_out(argv[3]);
  if (!file_matrix_out)
  {
    std::cout << "Error...";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    for (size_t i = 0; i < column; i++)
    {
      for (size_t j = 0; j < line; j++)
      {
        file_matrix_in >> matrix[column * i + j];
        if (!file_matrix_in)
          {
            std::cout << "elements read with an error";
            return 1;
          }
      }
    }
      file_matrix_out << countPositiveElOfCol(matrix, column, line) << "\n";
      if (!file_matrix_out)
      {
        std::cout << "number writes with an error";
        return 1;
      }
  }
  else
  {
    if (!std::strcmp(argv[1], "2"))
    {
      if (column * line == 0)
      {
        file_matrix_out << "empty file";
        return 0;
      }
      int* matrix = new int[column * line];
      for (size_t i = 0; i < column; i++)
      {
        for (size_t j = 0; j < line; j++)
        {
          file_matrix_in >> matrix[i * column + j];
          if (!file_matrix_in)
          {
            std::cout << "elements read with an error";
            delete[] matrix;
            return 1;
          }
        }
      }
      file_matrix_out << countUniqueElOfCol(matrix, column, line) << "\n";
      if (!file_matrix_out)
      {
        std::cout << "number writes with an error";
        return 1;
      }
      delete[] matrix;
    }
    else
    {
      std::cout << "Error...";
      return 1;
    }
  }
  return 0;
}
