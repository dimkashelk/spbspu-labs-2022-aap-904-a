#include "maxCountOfEqualElements.h"
#include <cstddef>

void countMaxQuantityOfEqualElements(const int* arr, const int size, size_t& count, size_t& maxCount)
{
  for (int i = 0; i < size - 1; ++i)
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
}
