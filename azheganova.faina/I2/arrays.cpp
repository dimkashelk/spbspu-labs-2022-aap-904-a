#include <iostream>
#include "arrays.h"

void shiftarrayleft(int* arr, const size_t size)
{
  int shiftamount = 0;
  int howmuchshiftnow = 0;
  std::cout << "Shift:\n";
  std::cin >> shiftamount;
  while (howmuchshiftnow++ < shiftamount)
  {
  int position1 = 0;
  int position2 = 0;
  position1 = arr[0];
    position2 = arr[1];
    for (size_t i = 0; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[size - 1] = position1;
    arr[size] = position2;
  }
}

void transferofvariables(int* arr, const size_t size)
{
  size_t begin = 3;
  size_t end = 5;
  size_t newi = 3;
  int* newarr= new int[newi];
  for (size_t i = begin; i <= end; i--)
  {
    newarr[i - begin] = arr[i];;
  }
  for (size_t i = end + 1; i < size; i++) 
  {
    arr[i - newi] = arr[i];
  }
  for (size_t i = size - newi; i < size; i++) 
  {
    arr[i] = newarr[i - size + newi];
  }
}
