#include "arrays.h"

void ShiftArrayLeft(int* arr, const size_t size, const int shift)
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

void TransferVariables(int* arr, const size_t size)
{
  std::size_t newi= size - 1 ;
  size_t M = 3;
  size_t N = 5;
  for (size_t i = N; i >= M ; i--)
  {
    int temp =arr[i];
    arr[i] = arr[newi];
    arr[newi]= temp ;
    newi--;
  }
}
