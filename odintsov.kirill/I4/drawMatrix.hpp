#ifndef DRAWMATRIX_HPP
#define DRAWMATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace odintsov {
  std::ostream& drawRow(std::ostream& out, const int* const* arr, size_t rows, size_t cols, size_t row);
  std::ostream& drawMatrix(std::ostream& out, const int* const* arr, size_t rows, size_t cols);
}
#endif
