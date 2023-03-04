#include "matrixWaveValue.h"
#include <cmath>
#include <stdexcept>
int* assignMatrixWaveValue(int *matrix, size_t cols, size_t rows, size_t index_row, size_t index_col)
{
  if (index_row > rows || index_col > cols)
  {
    throw std::invalid_argument("First number of indexes that are out");
  }
  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      int row_diff = abs(static_cast< int >(i) - static_cast< int >(index_col) + 1);
      int col_diff = abs(static_cast< int >(j) - static_cast< int >(index_row) + 1);
      matrix[i * rows + j] = std::max(row_diff, col_diff);
    }
  }
  return matrix;
}
