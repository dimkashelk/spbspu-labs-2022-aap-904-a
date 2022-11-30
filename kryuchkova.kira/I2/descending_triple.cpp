#include "descending_triple.h"
#include <cstddef>

unsigned int count_descending_triple(const int *array, const unsigned int size)
{
  unsigned int counter = 0;

  for (size_t i = 2; i < size; i++)
  {
    if (array[i - 2] > array[i - 1] && array[i - 1] > array[i])
    {
      counter++;
    }
  }

  return counter;
}
