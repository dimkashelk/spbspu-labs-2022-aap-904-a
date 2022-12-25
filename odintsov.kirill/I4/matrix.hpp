#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

namespace odintsov {
  int getMatrixVal(const int* arr, size_t rows, size_t cols, size_t x, size_t y);
  bool isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col);
  unsigned getColAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols);
  unsigned getRowAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols);
}

#endif
