#include "countmaximumelements.h"
#include <cstddef>
size_t count_maximum_elements(int *arr, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  size_t count = 0;
  int maximum = arr[0];
  for (size_t i = 0; i < size; i++)
  {
    if (maximum == arr[i])
    {
      count++;
    }
    else if (arr[i] > maximum)
    {
      maximum = arr[i];
      count = 1;
    }
  }
  return count;
}
