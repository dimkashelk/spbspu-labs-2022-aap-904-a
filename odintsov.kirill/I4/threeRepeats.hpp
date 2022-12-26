#ifndef THREEREPEATS_HPP
#define THREEREPEATS_HPP

#include <cstddef>

namespace odintsov {
  bool isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col);
  bool isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row);
  size_t countColsWithThreeRepeats(const int* arr, size_t rows, size_t cols);
  size_t countRowsWithThreeRepeats(const int* arr, size_t rows, size_t cols);
}

#endif
