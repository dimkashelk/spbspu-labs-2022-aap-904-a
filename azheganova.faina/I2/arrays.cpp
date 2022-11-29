#include <iostream>
#include "arrays.h"

void shiftarrayleft(int* arr, size_t size)
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

void transferofvariables(int* arr, size_t size)
{
  int begin = 0;
  int end = 0;
  int l = size;
  std::cin >> end;
  std::cin >> begin;
  std::size_t newi = l - 1;
  for (int i = begin; i >= end; i--)
  {
    arr[newi] = arr[i];
    newi--;
  }
}

void printArray(int arr[], const std::size_t size)
{
  for (std::size_t i = 0; i < size; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';
}
