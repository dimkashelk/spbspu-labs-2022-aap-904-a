#include "countRowsWithEqualSum.h"

size_t countRowsWithEqualSum(int* matrix, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    int rowSum = 0;
    for (size_t j = 0; j < cols; j++)
    {
      rowSum += matrix[i*cols + j];
    }
    for (size_t k = i + 1; k < rows; k++)
    {
      int nextRowSum = 0;
      for (size_t j = 0; j < cols; j++)
      {
        nextRowSum += matrix[k*cols + j];
      }
      if (nextRowSum == rowSum)
      {
        count++;
      }
    }
  }
  return count;
}
