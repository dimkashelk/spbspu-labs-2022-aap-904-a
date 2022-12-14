#include "decrease.h"
#include <limits>
#include <stdexcept>
unsigned int LengthOfDecreaseVal(const int *arr, const size_t size)
{
  unsigned int curleght = 0;
  unsigned int maxleght = 0;
  if (size == 0)
  {
    return 0 ;
  }
  for (size_t i = 0; i < size; ++i)
  {
    if (arr[i - 1] > arr[i])
    {
      curleght ++;
      if (curleght > maxleght)
      {
        maxleght = curleght;
      }
      if (curleght == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Overflow AntiSwag situation");
      }
    }
    if (arr[i - 1] < arr[i])
    {
      curleght = 0;
    }
  }
  return maxleght;
}
