#include <cstring>
#include <fstream>
#include <iostream>
#include "count_positive_columns.h"
#include "count_diagonals_without_zeros.h"
#include "make_square_matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "The arguments are wrong\n";
    return 1;
  }

  if (strcmp(argv[1], "1") && strcmp(argv[1], "2"))
  {
    std::cerr << "First argument must be the number of function: 1 or 2\n";
    return 1;
  }

  std::ifstream fin(argv[2]);
  if (!fin.is_open())
  {
    std::cerr << "Reading File could not be opened\n";
    return 1;
  }

  size_t rows = 0;
  size_t columns = 0;
  fin >> rows >> columns;
  if (!fin)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  if (rows * columns >= 1000)
  {
    std::cerr << "The matrix is bigger than the intended\n";
    return 1;
  }

  std::ofstream fout(argv[3]);
  if (!fout.is_open())
  {
    std::cerr << "Writing File could not be opened\n";
    return 1;
  }

  if (!strcmp(argv[1], "1"))
  {
    int array[1000];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        fin >> array[rows * i + j];
        if (!fin)
        {
          std::cerr << "Error while reading elements of matrix\n";
          return 2;
        }
      }
    }
    fout << countPositiveColumns(array, rows, columns);
    if (!fout)
    {
      std::cerr << "Error writing into file\n";
      return 1;
    }
  }
  else
  {
    if (rows * columns == 0)
    {
      fout << "0\n";
      if (!fout)
      {
        std::cerr << "Error while writing the result\n";
        return 1;
      }
      return 0;
    }
    int* dynamic_array = new int[rows * columns];

    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        fin >> dynamic_array[rows * i + j];
        if (!fin)
        {
          std::cerr << "Error while reading elements of matrix\n";
          delete[] dynamic_array;
          return 2;
        }
      }
    }
    int* square_array = nullptr;
    try
    {
      square_array = makeSquareMatrix(dynamic_array, rows, columns);
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamic_array;
      delete[] square_array;
      return 1;
    }

    fout << countDiagonalsWithoutZeros(square_array, rows);
    if (!fout)
    {
      std::cerr << "Error writing into file\n";
      delete[] dynamic_array;
      delete[] square_array;
      return 1;
    }
    delete[] dynamic_array;
    delete[] square_array;
  }
  return 0;
}
