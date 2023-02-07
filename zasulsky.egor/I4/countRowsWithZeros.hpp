#ifndef COUNTROWSWITHZEROS_HPP
#define COUNTROWSWITHZEROS_HPP

#include <cstddef>

namespace zasulsky {
  int getValueFromMatrix(int* matrix, size_t, size_t cols, size_t row, size_t col);
  bool rowHasZero(int* matrix, size_t, size_t cols, size_t row);
  size_t countRowsWithZeros(int* matrix, size_t rows, size_t cols);
}

#endif
