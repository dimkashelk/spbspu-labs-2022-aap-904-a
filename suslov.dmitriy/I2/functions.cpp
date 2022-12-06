#include "functions.h"
#include <algorithm>
void move_elements(int *arr, size_t size, size_t m, size_t n)
{
  if (size_t == 0)
  {
    return 0
  }
  for (size_t i = n; i >= m; i--)
  {
    std::swap(arr[i], arr[i + size - 2 - n]);
  }
}
double arithmetic_mean_of_even_indices(int *arr, size_t size)
{
  int sum = 0;
  for (size_t i = 0; i < size; i += 2)
  {
    sum += arr[i];
  }
  return static_cast< double >(sum) / static_cast< double >(size / 2);
}
