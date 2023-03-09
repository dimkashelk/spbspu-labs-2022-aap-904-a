#include "columns_without_null_elements.h"
#include <cstddef>

int countColumnsWithoutNull(const int* matrix, size_t row, size_t col)
{
  int count = 0;
  for (size_t i = 0; i < col; i++)
  {
    bool qu = false;
    for (size_t j = 0; j < row; j++)
    {
      if (matrix[col * j + i] != 0)
      {
        qu = true;
      }
      else
      {
        qu = false;
        break;
      }
    }
    if (!qu)
    {
      count++;
    }
  }
  return count;
}
