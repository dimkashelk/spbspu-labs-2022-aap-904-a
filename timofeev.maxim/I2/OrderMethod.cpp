#include "OrderMethod.h"
#include <algorithm>
#include <iostream>
int * Sort_Array(int * arr, size_t size1)
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
  //for (size_t p = 0; p < size1; p++)
  //{
    //std::cout << arr[p] << " " ;
  //}
  return arr;
}

