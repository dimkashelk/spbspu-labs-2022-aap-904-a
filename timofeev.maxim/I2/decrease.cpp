#include "decrease.h"
#include <limits>
#include <stdexcept>
unsigned int LengthOfDecreaseVal(const int *arr, size_t size)
{
  unsigned int curleght = 1;
  unsigned int maxleght = 1;
  if (size == 0)
  {
    std::cout << "Size AntiSwag situation" << "\n";
    return 0;
  }
  for (size_t i = 1; i < size; ++i)
  {
    if (arr[i - 1] > arr[i])
    {
      curleght++;
      if (curleght > maxleght)
      {
        maxleght = curleght;
      }
      if (curleght == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Overflow AntiSwag situation");
      }
    }
    if (arr[i] > arr[i - 1])
    {
      curleght = 1;
    }
  }
  return maxleght;
}
