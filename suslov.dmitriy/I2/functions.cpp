#include "functions.h"
#include <algorithm>
#include <stdexcept>
void move_elements(int *arr, size_t size, size_t m, size_t n)
{
  if (size == 0)
  {
    return;
  }
  for (size_t i = m; i <= n; i++)
  {
    std::swap(arr[i], arr[size - (n - i + 1)]);
  }
}
double arithmetic_mean_of_even_indices(int *arr, size_t size)
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
