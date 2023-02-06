#include "countDivValues.h"
size_t countDivValues(int *arr, size_t size, unsigned int k)
{
  size_t counter = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] % k == 0)
    {
      counter++;
    }
  }
  return k;
}
