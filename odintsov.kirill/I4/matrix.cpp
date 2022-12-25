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

size_t odintsov::countValRepeatsInRow(int val, const int* arr, size_t rows, size_t cols, size_t row)
{
  size_t count = 0;
  for (size_t i = 0; i < cols; i++) {
    if (val == getMatrixVal(arr, rows, cols, i, row)) {
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

bool odintsov::isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row)
{
  for (size_t i = 0; i < cols - 2; i++) {
    int val = getMatrixVal(arr, rows, cols, i, row);
    if (countValRepeatsInRow(val, arr, rows, cols, row)) {
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

unsigned odintsov::getRowAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols)
{
  unsigned rowsThreeRepeat = 0;
  for (size_t i = 0; i < rows; i++) {
    if (isThreeRepeatsInRow(arr, rows, cols, i)) {
      rowsThreeRepeat++;
    }
  }
  return rowsThreeRepeat;
}
