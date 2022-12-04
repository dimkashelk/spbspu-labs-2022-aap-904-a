#include "MaxElements.h"

int CountMaxElements(const int *array, const size_t size)
{
  size_t count = 0;
  int max_val = 0;
  for (size_t i = 0; i < size; i++)
    if (array[i] > max_val)
    {
      max_val = array[i];
      count = 1;
    }
    else if (max_val == array[i])
    {
      count++;
    }
  return count;
}
