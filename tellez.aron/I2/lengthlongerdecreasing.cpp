#include <cstddef>
#include "lengthlongerdecreasing.h"
size_t length_longer_decreasing(const int *arr, const size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  size_t max = 0;
  size_t len = 1;
  size_t i = 0;
  while (i < size - 1)
  {
    if (arr[i + 1] < arr[i])
    {
      len++;
    }
    else
    {
      if (max < len)
      {
        max = len;
        len = 1;
      }
    }
    i++;
  }
  if (max < len)
  {
    max = len;
  }
  return max;
}
