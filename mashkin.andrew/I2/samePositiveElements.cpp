#include "samePositiveElements.h"
#include <cstddef>

bool isThereTheSamePositiveElements(const int* arr, const size_t size, bool& ans)
{
  for (int i = 0; i < size - 1; ++i)
  {
    if (arr[i] < 1)
    {
      continue;
    }
    for (int j = i + 1; j < size; ++j)
    {
      if (arr[j] < 1)
      {
        continue;
      }
      ans = arr[i] == arr[j];
      if (ans)
      {
        return ans;
      }
    }
  }
  return ans;
}
