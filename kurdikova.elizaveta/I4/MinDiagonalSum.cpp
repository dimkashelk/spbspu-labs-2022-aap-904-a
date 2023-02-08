#include "MinDiagonalSum.h"


size_t minDiagonalSumParallelToSecondary(const int* matrix, const size_t rows)
{
  size_t minSum = std::numeric_limits<size_t>::max();
  // The upper half of the matrix is relative to the side diagonal
  for (size_t i = 0; i < rows - 1; i++)
  {
    size_t currentSum = 0;
    for (size_t j = 0; j <= i; j++)
    {
      currentSum += matrix[i + j * (rows - 1)];
    }
    if (minSum > currentSum)
    {
      minSum = currentSum;
    }
  }

  // The lower half of the matrix is relative to the side diagonal
  for (size_t i = 1; i < rows; i++)
  {
    size_t currentSum = 0;
    for (size_t j = 0; j < i; j++)
    {
      currentSum += matrix[rows * rows - i - j * (rows - 1)];
    }
    if (minSum > currentSum)
    {
      minSum = currentSum;
    }
  }
  return minSum;
}
