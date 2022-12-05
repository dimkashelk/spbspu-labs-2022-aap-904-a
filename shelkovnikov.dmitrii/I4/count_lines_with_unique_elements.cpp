#include "count_lines_with_unique_elements.h"
size_t count_lines_with_unique_elements(const int *arr, size_t n, size_t m)
{
  size_t count = 0;
  for (size_t i = 0; i < n; i++)
  {
    bool fl = true;
    for (size_t j = 0; j < n; j++)
    {
      for (size_t k = j + 1; k < m; k++)
      {
        if (arr[i * n + j] == arr[i * n + k])
        {
          fl = false;
          break;
        }
      }
      if (!fl)
      {
        break;
      }
    }
    if (fl)
    {
      count++;
    }
  }
  return count;
}