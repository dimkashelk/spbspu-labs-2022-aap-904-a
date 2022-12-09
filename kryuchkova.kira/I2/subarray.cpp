#include "subarray.h"
#include <cstddef>
#include <stdexcept>

unsigned int count_sequence_similar(const int *array, const unsigned int size)
{
  unsigned int max = 0;
  unsigned int counter = 1;

  for (size_t i = 1; i < size; i++)
  {
    if (array[i - 1] == array[i])
    {
      if (counter == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Overflow!");
      }
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
