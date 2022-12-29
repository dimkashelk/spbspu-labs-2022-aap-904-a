#include "largestdengthdecreasing.h"
size_t largest_dength_decreasing(const int *arr,const size_t size)
{
  int max = 0; 
  int len = 1;
  for (int i = 0; i < size-1; i++)
  {
    if (arr[i + 1] < arr[i])
      len++;
    else
    {
      if (max < len)
        max = len;
        len = 1;
    }
  }
  if (max < len)
    max = len;
  return max;
}
