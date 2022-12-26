#include "drawMatrix.hpp"
#include <cstddef>
#include <iostream>

std::ostream& drawMatrix(std::ostream& out, const int* const* arr, size_t rows, size_t cols)
{
  for (size_t r = 0; r < rows - 1; r++) {
    for (size_t c = 0; c < cols - 1; c++) {
      out << arr[r][c] << ' ';
    }
    out << arr[r][cols - 1] << '\n';
  }
  for (size_t c = 0; c < cols - 1; c++) {
    out << arr[rows - 1][c] << ' ';
  }
  return out << arr[rows - 1][cols - 1];
}
