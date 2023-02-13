#include "columns_w_positive_el.h"
bool isPositive(const int* matrix, size_t line, size_t columns, size_t& numberColumn)
{
  bool flag = true;
  size_t cnt = 0;
  size_t column_curr = 0;
  for (size_t i = 0; i < line; i++)
  {
    numberColumn = matrix[column_curr * i];
    if (*(matrix + columns * (numberColumn-1) * i) > 0)
    {
      flag = true;
      cnt++;
    }
    else
    {
      flag = false;
      return flag;
    }
  }
  return flag;
}
size_t countPositiveElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t columns_curr = 0;
  size_t count = 0;
  for (size_t i = 0; i < column; i++)
  {
    if (isPositive(matrix, line, column, columns_curr))
    {
      count++;
    }
  }
  return count;
}
