#include "columns_w_unique_el.h"
bool isUnique(const int* matrix, size_t column, size_t line)
{
  for(size_t i = 0; i < line; i++)
  {
    if(*(matrix + column * i) <= 0)
    {
      return false;
    }
  }
  return true;
}
size_t countUniqueElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t cnt = 0;
  for(size_t curr_column = 0; curr_column < column; curr_column++)
  {
    if (isUnique((matrix + column * 0 + curr_column), column, line))
    {
      cnt++;
    }
  }
  return cnt;
}
