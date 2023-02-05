#include "addIndicesElements.h"
#include <limits>
size_t add_indices_elements(const int *arr, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  int min = std::numeric_limits< int >::max();
  int max = std::numeric_limits< int >::min();
  size_t min_index = 0;
  size_t max_index = 0;
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
  size_t sum = max_index + min_index;
  return sum;
}
