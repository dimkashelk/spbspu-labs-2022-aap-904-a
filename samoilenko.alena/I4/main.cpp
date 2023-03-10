#include <iostream>
#include <fstream>
#include <cstring>
#include "columns_without_null_elements.h"
#include "rows_without_same_elements.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "File or parameters are incorrect";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Error during opening the file input.txt";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Error during opening the file output.txt";
    input.close();
    output.close();
  }
  size_t rows = 0;
  size_t columns = 0;
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Error with file" << '\n';
      input.close();
      output.close();
      return 1;
    }
    if (rows * columns > 1000)
    {
      std::cerr << "Matrix more than 1000";
      input.close();
      output.close();
      return 1;
    }
    for (size_t i = 0; i < rows * columns; i++)
    {
      input >> matrix[i];
      if (!input)
      {
        std::cerr << "Error during input matrix";
        input.close();
        output.close();
        return 1;
      }
    }
    output << countColumnsWithoutNull(matrix, rows, columns) << '\n';
    output << countRowsWithoutSameElements(matrix, rows, columns) << '\n';
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    input >> rows >> columns;
    if ((rows * columns) == 0)
    {
      output << "0" << '\n';
      return 0;
    }
    int* matrix1 = nullptr;
    try
    {
      matrix1 = new int[rows * columns];
    }
    catch (const std::bad_alloc& ex)
    {
      std::cerr << ex.what() << '\n';
      input.close();
      output.close();
      return 1;
    }
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        input >> matrix1[columns * i + j];
        if (!input)
        {
          std::cerr << "Error during input matrix" << '\n';
          delete[] matrix1;
          input.close();
          output.close();
          return 1;
        }
      }
    }
    output << countColumnsWithoutNull(matrix1, rows, columns) << '\n';
    output << countRowsWithoutSameElements(matrix1, rows, columns) << '\n';
    delete[] matrix1;
  }
  else
  {
    std::cerr << "Wrong number" << '\n';
    input.close();
    output.close();
    return 1;
  }
  input.close();
  output.close();
  return 0;
}
