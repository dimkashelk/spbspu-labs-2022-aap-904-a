#include "OrderMethod.h"
#include <algorithm>
unsigned int Sort_Array(int * arr, size_t size1)
{
  for (size_t k = 0; k < size1 - 1; k++)
  {
    for (size_t j = 0; j < size1 - 1; j++)
    {
      if (arr[j] % 2 == 1 && arr[j+1] % 2 == 0)
      {
        std::swap(arr[j],arr[j+1]);
      }
    }
  }
  return Sort_Array(arr, size1);
}
