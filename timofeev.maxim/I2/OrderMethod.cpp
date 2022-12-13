#include "OrderMrthod.h"
#include <algorithm>
void Sort_Array(const int * arr, size_t size)
{
  for (int i =0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1, j++)
    {
      if (arr[j] % 2 == 1 && arr[j+1] % 2 == 0)
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
  return Sort_Array;
}
