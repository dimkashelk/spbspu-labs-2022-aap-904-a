#include "drawMatrix.hpp"
#include <cstddef>
#include <iostream>

std::ostream& odintsov::drawRow(std::ostream& out, const int* const* arr, size_t, size_t cols, size_t row)
{
  for (size_t c = 0; c < cols - 1; c++) {
    out << arr[row][c] << ' ';
  }
  return out << arr[row][cols - 1];
}

std::ostream& odintsov::drawMatrix(std::ostream& out, const int* const* arr, size_t rows, size_t cols)
{
  for (size_t r = 0; r < rows - 1; r++) {
    drawRow(out, arr, rows, cols, r) << '\n';
  }
  return drawRow(out, arr, rows, cols, rows - 1);
}
