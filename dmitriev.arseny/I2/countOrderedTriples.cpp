#include "countOrderedTriples.h"

int countOrderedTriples(const int* const array, const int size)
{
  int count = 0;
  for (int i = 2; i < size; i++)
  {
    if (array[i] < array[i - 1])
    {
      if (array[i - 1] < array[i - 2])
      {
        count++;
      }
    }
  }
  return count;
}
