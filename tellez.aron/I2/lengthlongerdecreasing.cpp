#include "lengthlongerdecreasing.h"
size_t length_longer_decreasing(const int *arr, const size_t size)
{
  size_t max = 0;
  size_t len = 1;
  for (size_t i = 0; i < static_cast<size_t> (size - 1); i++)
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
  }
  if (max < len)
  {
    max = len;
  }
  return max;
}
