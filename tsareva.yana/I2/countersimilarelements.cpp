#include "countersimilarelements.h"
size_t count_similar_elements(const int *array, const size_t size)
{
  size_t t_count = 0;
  size_t count = 0;
  for (size_t i = 1; i < size; i++)
  {
    if (array[i - 1] == array[i])
    {
      t_count++;
    }
    else
    {
      if (t_count > count)
      {
        count = t_count;
      }
      t_count = 1;
    }
  }
  if (t_count > count)
  {
    count = t_count;
  }
  return count;
}

