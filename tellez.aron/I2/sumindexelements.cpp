#include "sumindexelements.h"
#include <climits>
#include <limits>
size_t sum_index_elements(const int *arr, const size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  int min = std::numeric_limits<int>::max();
  int max = std::numeric_limits<int>::min();
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  int sum = max + min;
  return sum;
}


