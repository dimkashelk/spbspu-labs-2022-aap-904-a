#include "threeRepeats.hpp"
#include <cstddef>
#include <unordered_map>

int odintsov::getMatrixVal(const int* arr, size_t rows, size_t, size_t x, size_t y)
{
  return arr[y * rows + x];
}

bool odintsov::isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col)
{
  std::unordered_map< int, unsigned > vals;
  for (size_t i = 0; i < rows; i++) {
    if (++(vals[getMatrixVal(arr, rows, cols, col, i)]) == 3) {
      return true;
    }
  }
  return false;
}

bool odintsov::isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row)
{
  std::unordered_map< int, unsigned > vals;
  for (size_t i = 0; i < cols; i++) {
    if (++(vals[getMatrixVal(arr, rows, cols, i, row)]) == 3) {
      return true;
    }
  }
  return false;
}

size_t odintsov::countColsWithThreeRepeats(const int* arr, size_t rows, size_t cols)
{
  size_t colsThreeRepeat = 0;
  for (size_t i = 0; i < cols; i++) {
    if (isThreeRepeatsInCol(arr, rows, cols, i)) {
      colsThreeRepeat++;
    }
  }
  return colsThreeRepeat;
}

size_t odintsov::countRowsWithThreeRepeats(const int* arr, size_t rows, size_t cols)
{
  size_t rowsThreeRepeat = 0;
  for (size_t i = 0; i < rows; i++) {
    if (isThreeRepeatsInRow(arr, rows, cols, i)) {
      rowsThreeRepeat++;
    }
  }
  return rowsThreeRepeat;
}
