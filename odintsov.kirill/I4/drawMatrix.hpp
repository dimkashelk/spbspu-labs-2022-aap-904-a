#ifndef DRAWMATRIX_HPP
#define DRAWMATRIX_HPP

#include <cstddef>
#include <iosfwd>

std::ostream& drawMatrix(std::ostream& out, const int* const* arr, size_t rows, size_t cols);

#endif
