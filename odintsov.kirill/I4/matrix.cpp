#include "matrix.hpp"
#include <cstddef>

int odintsov::getMatrixVal(const int* arr, size_t rows, size_t, size_t x, size_t y)
{
  return arr[y * rows + x];
}

bool odintsov::isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col)
{
  for (size_t i = 0; i < rows - 2; i++) {
    int val = getMatrixVal(arr, rows, cols, col, i);
    unsigned count = 1;
    for (size_t j = i + 1; j < rows; j++) {
      count++;
      if (count == 3) {
        return true;
      }
    }
  }
  return false;
}

unsigned odintsov::getColAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols)
{
  unsigned colsThreeRepeat = 0;
  for (size_t i = 0; i < cols; i++) {
    if (isThreeRepeatsInCol(arr, rows, cols, i)) {
      colsThreeRepeat++;
    }
  }
  return colsThreeRepeat;
}

unsigned odintsov::getRowAmtThreeRepeatVals(const int*, size_t, size_t)
{
  return 0;
}
