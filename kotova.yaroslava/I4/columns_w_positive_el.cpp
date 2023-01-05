#include "columns_w_positive_el.h"
size_t countPositiveElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t count = 0;
  for (size_t i = 0; i < column; i++)
  {
    for (size_t j = 0; j < line; j++)
    {
      for(size_t n = 0; n < line; n++)
      {
        if ((matrix[column * j + i] && matrix[column * n + i]) > 0 && j != n)
        {
          count++;
        }
      }
    }
  }
  return count;
}
