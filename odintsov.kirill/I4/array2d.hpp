#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

#include <cstddef>

namespace odintsov {
  int get2DArrayVal(const int* arr, size_t rows, size_t cols, size_t x, size_t y);
  unsigned getColAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols);
  unsigned getRowAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols);
}

#endif
