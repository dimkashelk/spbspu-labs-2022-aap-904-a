#include "maxCountOfEqualElements.h"
#include <cstddef>

size_t countMaxQuantityOfEqualElements(const int* arr, const size_t size)
{
  size_t count = 0;
  size_t maxCount = 0;
  for (size_t i = 0; i < size - 1; ++i)
  {
    if (arr[i] == arr[i + 1])
    {
      count = count == 0 ? 1 : count;
      count++;
      maxCount = maxCount < count ? count : maxCount;
    }
    else
    {
      count = 0;
    }
  }
  return maxCount;
}
