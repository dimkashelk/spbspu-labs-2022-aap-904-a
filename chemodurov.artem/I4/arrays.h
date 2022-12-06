#ifndef ARRAYS_H
#define ARRAYS_H
#include <cstddef>

namespace chemodurov
{
  size_t countGrowingRows(int * arr, size_t rows, size_t columns);
  unsigned long long calcMinSummSecondaryDiagonal(int * arr, size_t rows, size_t columns);
}
#endif
