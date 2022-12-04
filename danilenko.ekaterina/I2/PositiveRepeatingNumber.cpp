#include "PositiveRepeatingNumber.h"

int PosRepeatingNum(const int *array, const int size)
{
  int count = 0;
  for (int i = 0; i < size - 1; i++)
  {
    if (array[i] == array[i - 1])
      count++;
  }
  return count;
}
