#include "order.h"
#include <algorithm>
int *partition(int *arr, size_t size)
{
  if (size == 0 )
  {
    return 0;
  }
  for (size_t k = 0; k < size-1; k++)
  {
    for (size_t j = 0; j < size-1; j++)
    {
      if (arr[j] % 2 == 1 && arr[j+1] % 2 == 0)
      {
        std::swap(arr[j],arr[j+1]);
      }
    }
  }
  int *dividing = nullptr;
  for (size_t p = 0; p < size; p++)
  {
    if (arr[p] % 2 == 1)
    {
      dividing = &arr[p];
      break;
    }
  }
  if (dividing == nullptr)
  {
    return 0;
  }
  return dividing;
}
