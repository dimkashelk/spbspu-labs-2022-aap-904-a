#include "countorderedelements.h"
size_t count_ordered_elements(const int *arr, const size_t size)
{
  size_t count = 0;
  for (size_t i = 1; i < size; i++)
  {
    if (arr[i - 1] < arr[i])
    {
      count++;
    }
  }
  return count;
}
