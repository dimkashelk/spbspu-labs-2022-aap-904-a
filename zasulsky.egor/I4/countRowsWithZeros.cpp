#include "countRowsWithZeros.hpp"
#include <cstddef>
#include "matrixOperations.hpp"

bool zasulsky::rowHasZero(int* matrix, size_t rows, size_t cols, size_t row)
{
  for (size_t c = 0; c < cols; c++) {
    if (getMatrixValue(matrix, rows, cols, row, c) == 0) {
      return true;
    }
  }
  return false;
}

size_t zasulsky::countRowsWithZeros(int* matrix, size_t rows, size_t cols)
{
  size_t rowsWithZeros = 0;
  for (size_t r = 0; r < rows; r++) {
    if (rowHasZero(matrix, rows, cols, r)) {
      rowsWithZeros++;
    }
  }
  return rowsWithZeros;
}
