#include "count_columns_with_ascending_elements.h"
size_t count_columns_with_ascending_elements(const int **arr, const size_t size)
{
  size_t count = 0;
  for (size_t j = 0; j < m; j++)
  {
    bool fl = true;
    for (size_t i = 1; i < n; i++)
    {
      if (arr[i - 1][j] >= arr[i][j])
      {
        fl = false;
      }
    }
    if (fl)
    {
      count++;
    }
  }
  return count;
}
