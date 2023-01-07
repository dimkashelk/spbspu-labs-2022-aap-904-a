#include "sumindexelements.h"
#include <limits>
size_t sum_index_elements(const int *arr, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  int min = std::numeric_limits< int >::max();
  int max = std::numeric_limits< int >::min();
  int min_index = 0;
  int max_index = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
      min_index = i;
    }
    if (arr[i] > max)
    {
      max = arr[i];
      max_index = i;
    }
  }
  int sum = max_index + min_index;
  return sum;
}
