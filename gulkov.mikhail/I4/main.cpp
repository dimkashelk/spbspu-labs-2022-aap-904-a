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
<<<<<<< HEAD
    int *dyn_array = new int[cols * rows];
=======
    int *arr = new int[cols * rows];
>>>>>>> origin/gulkov.mikhail/I4
    for (unsigned int i = 0; i < cols; i++)
    {
      for (unsigned int j = 0; j < rows; j++)
      {
<<<<<<< HEAD
        in >> dyn_array[i * cols + j];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete[] dyn_array;
=======
        in >> arr[i * cols + j];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete[] arr;
>>>>>>> origin/gulkov.mikhail/I4
          return 1;
        }
      }
    }
    unsigned int index_row = 1;
    unsigned int index_col = 1;

<<<<<<< HEAD
    dyn_array = make_matrix_wave_increment(dyn_array, rows, cols, index_row, index_col);


=======
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
>>>>>>> origin/gulkov.mikhail/I4
  }
}