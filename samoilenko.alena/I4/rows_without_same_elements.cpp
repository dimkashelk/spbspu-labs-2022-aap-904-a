#include "rows_without_same_elements.h"
#include <cstddef>

size_t countRowsWithoutSameElements(const int* matrix, size_t row, size_t col)
{
  size_t count = 0;
  for (size_t i = 0; i < row - 1; i++)
  {
    bool b = false;
    for (size_t j = 0; j < col - 1; j++)
    {
      size_t dim = row * col + i;
      if (matrix[dim] != matrix[dim + 1])
      {
        b = true;
      }
      else
      {
        b = false;
        break;
      }
    }
    if (b == true)
    {
      count++;
    }
  }
  return count;
}
