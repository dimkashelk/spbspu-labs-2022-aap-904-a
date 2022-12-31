#include "SuminSmoothMatrix.hpp"

double summingInSmoothMatrix(const int *arr, size_t cols, size_t rows)
{
  double sum = 0;
  double *smooth_arr = new double[cols * rows];

  smoothingMatrix(arr, cols, rows, smooth_arr);

  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      if (j < i)
      {
        sum += std::abs(smooth_arr[cols * i + j]);
      }
    }
  }

  delete[] smooth_arr;

  return sum;
}
