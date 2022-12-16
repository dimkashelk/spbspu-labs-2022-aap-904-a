#include "PositiveRepeatingNumber.h"

bool PositiveRepeatingNumber(const int* array, const size_t size)
{
  bool count = false;
  for (size_t i = 1; i < size; i++)
  {
    if (array[i] == array[i - 1])
    {
      if (array[i] > 0)
      {
        count = true;
      }
    }
  }
  return count;
}
