#include "duplicateRows.h"
size_t countDuplicateRows(const int* arr, size_t m, size_t n)
{
  size_t count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      bool is_same = true;
      for (size_t k = 0; k < n; ++k)
      {
        if (arr[i * n + k] != arr[j * n + k])
        {
          is_same = false;
          break;
        }
      }
      if (is_same)
      {
        ++count;
        break;
      }
    }
  }
  return count;
}
