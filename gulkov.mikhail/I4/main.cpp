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
  in >> cols >> rows;

  if (!strcmp(argv[1], "1"))
  {
    if (!in)
    {
      std::cout << "Error while reading file\n";
      return 1;
    }

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

    std::cout << count_positive_cols(array, cols) << " positive cols in the matrix\n";

  }
  if (!strcmp(argv[1], "2"))
  {
    int *arr = new int[cols * rows];
    for (unsigned int i = 0; i < cols; i++)
    {
      for (unsigned int j = 0; j < rows; j++)
      {
        in >> arr[i * cols + j];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete[] arr;
          return 1;
        }
      }
    }
    unsigned int index_row = 1;
    unsigned int index_col = 1;

    arr = make_matrix_wave_increment(arr, rows, cols, index_row, index_col);

    for (unsigned int i = 0, str = 0; i < cols * rows; i++)
    {
      std::cout << arr[i] << " ";
      str++;
      if (str == 3)
      {
        std::cout << "\n";
        str = 0;
      }
    }
  }
}