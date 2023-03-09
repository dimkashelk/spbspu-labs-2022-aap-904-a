#include <iostream>
#include <fstream>
#include <cstring>
#include "columns_without_null_elements.h"
#include "rows_without_same_elements.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "File or parameters are incorrect";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cout << "Error during opening the file input.txt";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cout << "Error during opening the file output.txt";
    input.close();
    output.close();
  }
  size_t rows = 0;
  size_t columns = 0;
  input >> rows >> columns;
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    if (rows * columns > 1000)
    {
      std::cout << "Matrix more than 1000";
      return 1;
    }
    for (size_t i = 0; i < rows * columns; i++)
    {
      input >> matrix[i];
      if (!input)
      {
        std::cout << "Error during input matrix";
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
    if (!input)
    {
      std::cout << "Error during input matrix";
      input.close();
      output.close();
      return 1;
    }
  }
  return 0;
}