#include <cstring>
#include <fstream>
#include <iostream>
#include "count_positive_columns.h"
#include "count_diagonals_without_zeros.h"
using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    cerr << "The arguments are wrong\n";
    return 1;
  }

  if (argv[1] != '1' && argv[2] != '2')
  {
    cerr << "First argument must be the number of function: 1 or 2\n";
    return 1;
  }

  ofstream fin(argv[2], ios_base::in);
  if (!fin.is_open())
  {
    cerr << "Reading File could not be opened\n";
    return 1;
  }

  size_t rows = 0;
  size_t columns = 0;
  fin >> rows >> columns;
  if (!fin || rows*columns == 0)
  {
    cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }

  ofstream fout(argv[3], ios_base::out);
  if (!fout.is_open())
  {
    cerr << "Writing File could not be opened\n";
    return 1;
  }

  if (argv[1] == '1')
  {
    if (rows * columns >= 1000)
    {
      cerr << "The matrix is bigger than the intended\n";
      return 1;
    }
    int array[rows][columns];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        fin >> array[i][j];
        if (!fin)
        {
          std::cerr << "Error while reading elements of matrix\n";
          return 1;
        }
      }
    }
    fout << countPositiveColumns(array, rows, columns);
    if (!fout)
    {
      cerr << "Error writing into file\n";
      return 1;
    }
  }
  else
  {
    int** dynamic_array = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
      dinamic_array[i] = new int[columns];
    }

    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        fin >> dynamic_array[i][j];
        if (!fin)
        {
          cerr << "Error while reading elements of matrix\n";
          for (size_t s = 0; s < rows; s++)
          {
            delete[] dynamic_array[s];
          }
          delete[] dynamic_array;
          return 1;
        }
      }
    }
    fout << countDiagonalsWithoutZeros(dynamic_array, rows, columns);
    if (!fout)
    {
      cerr << "Error writing into file\n";
      return 1;
    }
    for (size_t s = 0; s < rows; s++)
    {
      delete[] dynamic_array[s];
    }
    delete[] dynamic_array;
  }
  return 0;
}
