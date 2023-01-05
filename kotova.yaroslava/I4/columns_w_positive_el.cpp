#include "columns_w_positive_el.h"
size_t countPositiveElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t count = 0;
  for (size_t i = 0; i < column; i++)
  {
    for (size_t j = 0; j < line; j++)
    {
      if (matrix[column * i + j] > 0)
      {
        count++;
      }
  }
  return count;
}
