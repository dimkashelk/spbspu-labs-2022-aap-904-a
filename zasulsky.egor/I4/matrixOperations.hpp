#ifndef MATRIXOPERATIONS_HPP
#define MATRIXOPERATIONS_HPP

#include <cstddef>
#include <iosfwd>

namespace zasulsky {
  size_t getMatrixIndex(size_t, size_t cols, size_t row, size_t col);
  int getMatrixValue(int* matrix, size_t rows, size_t cols, size_t row, size_t col);
  std::istream& fillMatrixFromStream(int* matrix, size_t rows, size_t cols, std::istream& in);
  std::istream& fillRowFromStream(int** matrix, size_t rows, size_t cols, size_t row, std::istream& in);
  std::istream& fillMatrixFromStream(int** matrix, size_t rows, size_t cols, std::istream& in);
}

#endif
