#include "countColumnNoZero.h"
#include <cstddef>

size_t countColumnNoZero(const int* matrix, size_t line, size_t column)
{
  size_t count = 0;
  bool zeroEl = 0;

  for (size_t i = 0; i < column; i++)
  {
    zeroEl = 0;
    for (size_t j = 0; j < line; j++)
    {
      if (matrix[column * j + i] == 0)
      {
        zeroEl = 1;
      }
    }
    if (!zeroEl)
    {
      count++;
    }
  }

  return count;
}
