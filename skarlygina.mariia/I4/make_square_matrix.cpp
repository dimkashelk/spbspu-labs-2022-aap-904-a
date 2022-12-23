#include "make_square_matrix.h"
#include <algorithm>
int* makeSquareMatrix(int* array, size_t& rows, size_t columns)
{
  size_t square_size = std::min(rows, columns);
  int* square_array = nullptr;
  rows = square_size;
  if (columns == rows)
  {
    return array;
  }
  square_array = array;
  delete[] array;
  array = nullptr;
  array = new int[square_size * square_size];
  if (columns < rows)
  {
    for (size_t i = 0; i < (square_size * square_size); ++i)
    {
      array[i] = square_array[i];
    }
  }
  else if (columns > rows)
  {
    for (size_t i = 0; i < square_size; ++i)
    {
      for (size_t j = 0; j < square_size; ++j)
      {
        array[(i * square_size) + j] = square_array[(i * columns) + j];
      }
    }
  }
  delete[] square_array;
  return array;
}
