#include "counterpositiveelements.h"
size_t count_positive_elements(const int *array, const size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  int min = array[0];
  size_t t_count = 0;
  size_t count = 0;
  for (size_t i = 1; i < size; i++)
  {
    if (min > array[i])
    {
      min = array[i];
      count = t_count;
    }
    if (array[i] > 0)
    {
      t_count++;
    }
  }
  return count;
}
