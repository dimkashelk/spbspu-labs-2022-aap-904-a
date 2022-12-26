#include "threeRepeats.hpp"
#include <cstddef>
#include <unordered_map>
#include "getMatrixValue.hpp"

bool odintsov::isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col)
{
  std::unordered_map< int, unsigned > vals;
  for (size_t i = 0; i < rows; i++) {
    if (++(vals[odintsov::getMatrixValue(arr, rows, cols, i, col)]) == 3) {
      return true;
    }
  }
  return false;
}

bool odintsov::isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row)
{
  std::unordered_map< int, unsigned > vals;
  for (size_t i = 0; i < cols; i++) {
    if (++(vals[odintsov::getMatrixValue(arr, rows, cols, row, i)]) == 3) {
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
