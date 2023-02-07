#ifndef MATRIXWRAPPER_HPP
#define MATRIXWRAPPER_HPP

#include <cstddef>

namespace zasulsky {
  struct MatrixWrapper {
    int** matrix;
    size_t rows, cols;

    MatrixWrapper(size_t rows, size_t cols);
    ~MatrixWrapper();
  };
}

#endif
