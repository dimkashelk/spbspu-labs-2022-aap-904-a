#include "columns_w_unique_el.h"
size_t countUniqueElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t count = 0;
  for (size_t i = 0; i < column; i++)
  {
    for (size_t j = 0; j < line - 1; j++)
    {
      for(size_t n = 0; n < line - 1; n++)
      {
        if (matrix[column * j + i] != matrix[(column * j + 1) + i])
        {
          if (matrix[column * n + i] != matrix[(column * n + 1) + i])
          {
            count++;
          }
        }
        if (j == n)
        {
          count = 0;
        }
      }
    }
  }
  return count;
}
