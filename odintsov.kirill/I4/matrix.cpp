#include "matrix.hpp"
#include <cstddef>

int odintsov::getMatrixVal(const int* arr, size_t rows, size_t, size_t x, size_t y)
{
  return arr[y * rows + x];
}

size_t odintsov::countValRepeatsInCol(int val, const int* arr, size_t rows, size_t cols, size_t col) {
  size_t count = 0;
  for (size_t i = 0; i < rows; i++) {
    if (val == getMatrixVal(arr, rows, cols, col, i)) {
      count++;
    }
  }
  return count;
}

bool odintsov::isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col)
{
  for (size_t i = 0; i < rows - 2; i++) {
    int val = getMatrixVal(arr, rows, cols, col, i);
    if (countValRepeatsInCol(val, arr, rows, cols, col) >= 3) {
      return true;
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

bool odintsov::isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row)
{
  for (size_t i = 0; i < cols - 2; i++) {
    int val = getMatrixVal(arr, rows, cols, i, row);
    unsigned count = 1;
    for (size_t j = i + 1; j < cols; j++) {
      if (val == getMatrixVal(arr, rows, cols, j, row)) {
        count++;
        if (count == 3) {
          return true;
        }
      }
    }
  }
  return false;
}

unsigned odintsov::getRowAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols)
{
  return 0;
}
