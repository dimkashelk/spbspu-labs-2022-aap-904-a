#include "cnt.max.elem.h"

size_t CounterMaxElement(const int *arr, const int size)
{
  size_t cnt_max = 0;
  size_t max = 0;
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
