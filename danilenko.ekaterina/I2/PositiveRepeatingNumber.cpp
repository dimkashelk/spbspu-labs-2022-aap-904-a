#include "PositiveRepeatingNumber.h"

int PosRepeatingNum(const int *array, const size_t size)
{
  size_t count = 0;
  for (size_t i = 0; i < size - 1; i++)
  {
    if (array[i] == array[i - 1])
      count++;
  }
  return count;
}
