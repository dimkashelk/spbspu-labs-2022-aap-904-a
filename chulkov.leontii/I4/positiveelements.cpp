#include "positiveelements.h"
#include <cstddef>

size_t countPositiveOnlyRows(int* matrix, size_t countRows, size_t countColumns)
{
  size_t count = 0;
  for (size_t row = 0; row < countRows; row++)
  {
    bool negative = true;
    for (size_t column = 0; column < countColumns; column++)
    {
      if (matrix[row * column + column] < 0)
      {
        negative = false;
        break;
      }
    }
    if (negative)
    {
      count++;
    }
  }
  return count;
}
