#include "arrays.h"
#include <stdexcept>

size_t chemodurov::countGrowingRows(const int * arr, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    size_t counter_in_row = 0;
    for (size_t j = 0; j < cols - 1; ++j)
    {
      size_t number_of_item = (i * cols) + j;
      if (arr[number_of_item] > arr[number_of_item + 1])
      {
        counter_in_row++;
      }
    }
    if (counter_in_row == (cols - 1))
    {
      counter++;
    }
  }
  return counter;
}

long long chemodurov::calcMinSummSecondaryDiagonal(const int * arr, size_t rows, size_t cols)
{
  if (rows != cols)
  {
    throw std::invalid_argument("No diagonal in not square matrix\n");
  }
  long long summ = 0;
  long long max_summ = 0;
  for (size_t i = 0; i < (2 * rows) - 1; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      for (size_t k = 0; k < cols; ++k)
      {
        if ((j + k) == i)
        {
          summ += arr[(j * cols) + k];
        }
      }
    }
    if (summ < max_summ)
    {
      max_summ = summ;
    }
    summ = 0;
  }
  return max_summ;
}
