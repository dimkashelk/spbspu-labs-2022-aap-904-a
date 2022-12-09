#include "descending_triple.h"
#include <cstddef>
#include <stdexcept>
#include <limits>

unsigned int count_descending_triple(const int *array, const unsigned int size)
{
  unsigned int counter = 0;

  for (size_t i = 2; i < size; i++)
  {
    if (array[i - 2] > array[i - 1] && array[i - 1] > array[i])
    {
      if (counter == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Overflow!");
      }
      counter++;
    }
  }

  return counter;
}
