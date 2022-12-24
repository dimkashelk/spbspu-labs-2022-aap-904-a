#include "countLinesNoZero.h"
#include <cstddef>

size_t countLinesNoZero(const int* matrix, size_t line, size_t column)
{
  size_t count = 0;
  bool zeroEl = 0;
  for (size_t i = 0; i < line; i++)
  {
    zeroEl = 0;
    for (size_t j = 0; j < column; j++)
    {
      if (matrix[column * i + j] == 0)
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