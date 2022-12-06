#include "arrays.h"
#include <stdexcept>

size_t chemodurov::countGrowingRows(int * arr, size_t rows, size_t cols)
{
  size_t counter = 0;
  size_t number_of_item = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    size_t counter_in_row = 0;
    for (size_t j = 0; j < cols - 1; ++j)
    {
      number_of_item = i * cols + j;
      if (arr[number_of_item] > arr[number_of_item + 1])
      {
        counter_in_row++;
      }
    }
    if (counter_in_row == cols - 1)
    {
      counter++;
    }
  }
  return counter;
}

unsigned long long chemodurov::calcMinSummSecondaryDiagonal(int * arr, size_t rows, size_t cols)
{
  if (rows != cols)
  {
    throw std::invalid_argument("No diagonal in not square matrix\n");
  }
  unsigned long long summ = 0;
  unsigned long long max_summ = 0;
  size_t number_of_item = 0;
  for (size_t i = 0; i < 2 * rows - 1; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      for (size_t k = 0; k < cols; ++k)
      {
        number_of_item = j * cols + k;
        if (j + k == i)
        {
          summ += arr[number_of_item];
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
