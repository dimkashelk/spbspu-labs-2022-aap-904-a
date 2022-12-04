#include "MaxElements.h"

int CountMaxElements(const int* array, const int size)
{
  int count = 0;
  int max_val = 0;
  for (int i = 0; i < size; i++)
    if (array[i] > max_val)
    {
      max_val = array[i];
      count = 1;
    }
    else if (max_val == array[i])
    {
      count++;
    }
  return count;
}
