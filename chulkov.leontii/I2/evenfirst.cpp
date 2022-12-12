#include "evenfirst.h"
#include <utility>
#include <cstddef>

void evenFirst(int* arr, const size_t size)
{
  if (size <= 1)
  {
    return;
  }
  unsigned i = 0;
  unsigned j = size - 1;
  while (i < j)
  {
    while (arr[i] % 2 != 1 && i < j)
    {
      i++;
    }
    while (arr[j] % 2 != 0 && i < j)
    {
      j--;
    }
    if (i >= j)
    {
      break;
    }
    std::swap(arr[i], arr[j]);
  }
}
