#include "subarray.h"
#include <cstddef>

unsigned int count_sequence_similar(const int *array, const unsigned int size)
{
  unsigned int max = 0;
  unsigned int counter = 1;

  for (size_t i = 1; i < size; i++)
  {
    if (array[i - 1] == array[i])
    {
      counter++;
      if (counter > max)
      {
        max = counter;
      }
    }
    else
    {
      counter = 1;
    }
  }

  return max;
}
