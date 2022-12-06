#include "movearrayleft.h"

void moveArrayLeft(int* arr, const size_t size, const int shift)
{
  int howmuchshiftnow = 0;
  while (howmuchshiftnow++ < shift)
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
