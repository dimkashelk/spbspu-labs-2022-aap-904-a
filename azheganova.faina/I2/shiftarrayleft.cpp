#include <iostream>
#include "shiftarrayleft.h"

size_t shiftarrayleft(int* arr, const size_t size)
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
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  return 0;
}
