#include "make_square_matrix.h"
int* makeSquareMatrix(const int* array, size_t& rows, size_t columns) 
{
  size_t square_size = std::min(rows, columns);
  rows = square_size;
  int* square_array = nullptr;
  if (columns == rows)
  {
    square_array = array;
    array = nullptr;
    return square_array;
  }
  square_array = new int[square_size * square_size];
  if (columns < rows)
  {
    for (size_t i = 0; i < (square_size * square_size); ++i)
    {
      square_array[i] = array[i];
    }
  }
  else if (columns > rows)
  {
    for (size_t i = 0; i < square_size; ++i)
    {
      for (size_t j = 0; j < square_size; ++j)
      {
        square_array[(i * square_size) + j] = array[(i * columns) + j];
      }
    }
  }
  return square_array;
}
