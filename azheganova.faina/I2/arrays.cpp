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
  int l = size;
  size_t begin = 5;
  size_t end = 3;
  std::size_t newi = l - 1;
  for (size_t i = begin; i >= end; i--)
  {
    arr[newi] = arr[i];
    newi--;
  }
}
