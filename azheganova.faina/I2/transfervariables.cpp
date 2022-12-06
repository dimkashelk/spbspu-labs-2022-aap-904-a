#include "transfervariables.h"

void transferVariables(int* arr, const size_t size)
{
  std::size_t newi= size - 1 ;
  size_t M = 3;
  size_t N = 5;
  if (size > N)
  {
    for (size_t i = N; i >= M ; i--)
    {
      int temp =arr[i];
      arr[i] = arr[newi];
      arr[newi]= temp ;
      newi--;
    }
  }
}
