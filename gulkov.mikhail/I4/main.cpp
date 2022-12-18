#include <iostream>
#include <fstream>
#include <cstring>
#include "CountPositiveCols.hpp"
#include "MakeMatrixWaveIncrement.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error, 4 arguments expected\n";
    return 1;
  }

  unsigned int cols = 0;
  unsigned int rows = 0;
  std::ifstream in(argv[2]);
  in >> cols;
  in >> rows;

  if (!in)
  {
    std::cerr << "Error while reading file\n";
    return 1;
  }

  if (!strcmp(argv[1], "1"))
  {

    int array[1000];

    if (rows * cols > 1000)
    {
      std::cerr << "Error, too big matrix\n";
      return 1;
    }

    for (size_t i = 0; i < cols; i++)
    {
      for (size_t j = 0; j < rows; j++)
      {
        in >> array[cols * i + j];
        if (!in)
        {
          std::cerr << "Error while reading file\n";
          return 1;
        }
      }
    }

    std::ofstream out(argv[3]);
    out << count_positive_cols(array, cols);

    if (!out)
    {
      std::cerr << "Error while writing file\n";
    }


  }
  else if (!strcmp(argv[1], "2"))
  {
    int *dyn_array = nullptr;

    try
    {
      dyn_array = new int[cols * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Error:\n";
      std::cerr << e.what();
      return 1;
    }

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

    try
    {
      dyn_array = make_matrix_wave_increment(dyn_array, rows, cols, index_row, index_col);
    }
    catch (const std::invalid_argument &e)
    {
      delete[] dyn_array;
      std::cerr << "Error:\n";
      std::cerr << e.what();
      return 1;
    }

    std::ofstream out(argv[3]);

    for (size_t i = 0; i < cols; i++)
    {
      for (size_t j = 0; j < rows; j++)
      {
        out << dyn_array[cols * i + j];
        i == (cols * rows - 1) ? out << "" : out << ' ';
        if (!in)
        {
          std::cerr << "Error while writing file\n";
          return 1;
        }
      }
    }

  }
}
