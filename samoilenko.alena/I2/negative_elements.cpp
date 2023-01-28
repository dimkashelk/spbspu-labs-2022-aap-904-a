#include <cstddef>
#include "negative_elements.h"
size_t negativeElementsAfterMax(int *array, size_t size)
{
  int maximum = array[0];
  size_t counter = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] > maximum)
    {
      maximum = array[i];
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] < 0 && array[i - 1] == maximum)
    {
      counter += 1;
    }
    return(counter);
  }
}