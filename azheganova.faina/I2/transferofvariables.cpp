#include <iostream>
#include "transferofvariables.h"

size_t transferofvariables(int* arr, const size_t size)
{
  int begin;
  int end;
  int l = size;
  std::cin >> end;
  std::cin >> begin;
  std::size_t newi = l - 1;
  for (int i = begin; i >= end; i--)
  {
    arr[newi] = arr[i];
    newi--;
  }
  for (int newi = 0; newi < size; newi++)
  {
    std::cout << arr[newi]<< ' ';
  }
  return 0;
}
