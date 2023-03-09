#include "rows_without_same_elements.h"
#include <cstddef>

size_t countRowsWithoutSameElements(const int* matrix, size_t row, size_t col)
{
  size_t count = 0;
  for (size_t i = 0; i < col - 1; i++)
  {
    size_t dim = row * col + i;
    bool b = false;
    for (size_t j = 0; j < row - 1; j++)
    {
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
