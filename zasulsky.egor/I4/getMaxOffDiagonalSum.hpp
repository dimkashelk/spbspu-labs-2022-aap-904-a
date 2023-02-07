#ifndef GETMAXOFFDIAGONALSUM_HPP
#define GETMAXOFFDIAGONALSUM_HPP

#include <cstddef>

namespace zasulsky {
  int getDiagonalSum(int** matrix, size_t rows, size_t cols, size_t diagIndex);
  int getMaxOffDiagonalSum(int** matrix, size_t rows, size_t cols);
}

#endif
