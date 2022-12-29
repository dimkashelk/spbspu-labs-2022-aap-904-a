#include "sumindexelements.h"
#include <climits>
size_t sum_index_elements(const int *arr, const size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  int min = INT_MAX;
  int max = INT_MIN;
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
  int sum= max + min;
  return sum;
}


