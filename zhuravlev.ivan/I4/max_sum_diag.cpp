#include "max_sum_diag.h"
#include <cstddef>
#include <algorithm>
#include <iostream>


int sumOfParallelDiagBelowTheMainDiag(const int* arr, const size_t dyn_size)
{
  int summ = 0;
  for (size_t i = 0; i < dyn_size; ++i)
  {
    for (size_t j = 0; j < dyn_size; ++j)
    {
      summ += arr[dyn_size + j * (j + i)];
    }
  }
  return summ;
}

int sumOfParallelDiagUnderTheMainDiag(const int* arr, const size_t dyn_size)
{
  int summ = 0;
  for (size_t i = 0; i < dyn_size; ++i)
  {
    for (size_t j = 0; j < dyn_size; ++j)
    {
      summ += arr[dyn_size * j + (j - i)];
    }
  }
  return summ;
}



int maxSumDiag(int* arr, size_t nRows, size_t nColomns)
{
  size_t dyn_size = nRows * nColomns;
  if (dyn_size == 0)
  {
    std::cerr << "Matrix dont exist";
  }
  int max_sum_diag = 0;
  for (size_t i = 0; i < dyn_size; i++)
  {
    int below_main_diag_summ = sumOfParallelDiagBelowTheMainDiag(arr, dyn_size);
    int under_main_diag_summ = sumOfParallelDiagUnderTheMainDiag(arr, dyn_size);
    max_sum_diag = std::max(max_sum_diag, std::max(below_main_diag_summ, under_main_diag_summ));
  }
  return max_sum_diag;
}
