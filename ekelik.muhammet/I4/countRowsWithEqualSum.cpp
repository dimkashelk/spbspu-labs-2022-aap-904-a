#include "countRowsWithEqualSum.h"

size_t countRowsWithEqualSum(const int* matrix, size_t numRows, size_t numCols)
{
  size_t count = 0;
  for (size_t i = 0; i < numRows; i++)
  {
    int rowSum = 0;
    for (size_t j = 0; j < numCols; j++)
    {
      rowSum += matrix[numCols * i + j];
    }
    for (size_t j = i + 1; j < numRows; j++)
    {
      int nextRowSum = 0;
      for (size_t k = 0; k < numCols; k++)
      {
        nextRowSum += matrix[numCols * j + k];
      }
      if (rowSum == nextRowSum)
      {
        count++;
      }
    }
  }
  return count;
}
