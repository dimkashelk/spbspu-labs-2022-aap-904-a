#include "diagonalSum.hpp"
#include <cstddef>

int odintsov::getOffDiagonalSumByPoint(const int* const* arr, size_t rows, size_t cols, size_t row, size_t col)
{
  int sum = 0;
  for (size_t r = row, c = col; c < cols; r--, c++) {
    sum += arr[r][c];
    if (r == 0) {
      break;
    }
  }
  if (col == 0) {
    return sum;
  }
  for (size_t r = row + 1, c = col - 1; r < rows; r++, c--) {
    sum += arr[r][c];
    if (c == 0) {
      break;
    }
  }
  return sum;
}

int odintsov::getMinOffDiagonalSum(const int* const* arr, size_t rows, size_t cols)
{
  int minSum = getOffDiagonalSumByPoint(arr, rows, cols, 0, 0);
  for (size_t r = 1; r < rows; r++) {
    int newSum = getOffDiagonalSumByPoint(arr, rows, cols, r, 0);
    if (newSum < minSum) {
      minSum = newSum;
    }
  }
  return minSum;
}
