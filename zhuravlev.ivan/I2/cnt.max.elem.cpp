#include "cnt.max.elem.h"

size_t CounterMaxElement(const int *arr, const int size)
{
  int cnt_max = 0;
  int max = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == max)
  {
    cnt_max++;
  }
 }
  return cnt_max;
}
