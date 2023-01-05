#include "columns_w_unique_el.h"
size_t countUniqueElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t count = 0;
    for (size_t i = 0, j = 0; i < column, j < line; i++, j++)
    {
      if (matrix[column * i + j] == matrix[column * i + j + 1])
      {
        count++;
      }
    }
  return count;
}
