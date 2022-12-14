#include "arithmetic_mean_of_even_indices.h"
double arithmetic_mean_of_even_indices(const int *arr, size_t size)
{
  if (size == 0)
  {
    throw std::runtime_error("Zero size");
  }
  double sum = 0;
  for (size_t i = 0; i < size; i += 2)
  {
    sum += arr[i];
  }
  return sum / static_cast< double >(size / 2);
}
