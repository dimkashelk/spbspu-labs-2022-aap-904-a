#include "MatrixWrapper.hpp"
#include <cstddef>

zasulsky::MatrixWrapper::MatrixWrapper(size_t rows, size_t cols):
  rows(rows),
  cols(cols),
  matrix(new int*[rows])
{
  for (size_t i = 0; i < rows; i++) {
    try {
      matrix[i] = new int[cols];
    } catch (...) {
      for (size_t j = 0; j < i; j++) {
        delete [] matrix[j];
      }
      delete [] matrix;
      throw;
    }
  }
}

zasulsky::MatrixWrapper::~MatrixWrapper()
{
  for (size_t i = 0; i < rows; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
}
