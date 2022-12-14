#include "MakeMatrixWaveIncrement.hpp"
#include <stdexcept>

int *make_matrix_wave_increment(int *matrix, unsigned int cols, unsigned int rows, unsigned int index_row, unsigned int index_col)
{
  if (index_row > rows || index_col > cols)
  {
    throw std::invalid_argument("Error: main number indexes are out of bounds.");
  }

  index_row--;
  index_col--;

  matrix[cols * index_row + index_col] = 1;

  for (unsigned int i = 0; i < cols; i++)
  {
    for (unsigned int j = 0; j < rows; j++)
    {
      unsigned int row_difference = std::max(i, index_row) - std::min(i, index_row);
      unsigned int col_difference = std::max(j, index_col) - std::min(j, index_col);
      matrix[cols * i + j] = std::max(row_difference, col_difference) + 1;
    }
  }

  return matrix;
}