#include <iostream>
#include <fstream>
#include <cstring>
#include "CountPositiveCols.hpp"
#include "MakeMatrixWaveIncrement.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Error, 4 arguments expected\n";
    return 1;
  }

  unsigned int cols = 0;
  unsigned int rows = 0;
  std::ifstream in(argv[2]);
  in >> cols;
  in >> rows;

  if (!in)
  {
    std::cout << "Error while reading file\n";
    return 1;
  }

  if (!strcmp(argv[1], "1"))
  {

    int array[1000];

    for (size_t i = 0; i < cols; i++)
    {
      for (size_t j = 0; j < rows; j++)
      {
        in >> array[cols * i + j];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          return 1;
        }
      }
    }

    std::ofstream out(argv[3]);
    out << count_positive_cols(array, cols) << " positive cols in the matrix\n";
    if (!out)
    {
      std::cout << "Error while writing file\n";
    }

  }
  else if (!strcmp(argv[1], "2"))
  {
    int *dyn_array = new int[cols * rows];
    for (unsigned int i = 0; i < cols; i++)
    {
      for (unsigned int j = 0; j < rows; j++)
      {
        in >> dyn_array[i * cols + j];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete[] dyn_array;
          return 1;
        }
      }
    }
    unsigned int index_row = 1;
    unsigned int index_col = 1;

    dyn_array = make_matrix_wave_increment(dyn_array, rows, cols, index_row, index_col);

    std::ofstream out(argv[3]);

    for (unsigned int i = 0; i < cols * rows; i++)
    {
      out << dyn_array[i];
      i == (cols * rows - 1) ? out << "" : out << ' ';
    }
  }
}
