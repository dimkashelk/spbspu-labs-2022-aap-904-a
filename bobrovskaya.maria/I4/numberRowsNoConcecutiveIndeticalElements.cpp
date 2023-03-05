#include "numberRowsNoConcecutiveIndeticalElements.h"

bool isGrowingElements(const int *matrix, size_t rows, size_t column)
{
  for (size_t i = 0; i < column - 1; i++)
  {
    size_t order1 = rows * column + i;
    if (matrix[order1] == matrix[order1 + 1])
    {
      return false;
    }
  }
  return true;
}

size_t numberRowsNoConcecutiveIndeticalElements(const int *matrix, size_t rows, size_t column)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    if (isGrowingElements(matrix, i, column))
    {
      count++;
    }
  }
  return count;
}
