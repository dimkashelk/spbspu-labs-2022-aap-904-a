#include "shiftArray.h"
#include <stdexcept>
#include <cstddef>

void shiftArray(int* array, const size_t size, size_t shift)
{
  if (size != 0)
  {
    shift = shift % size;
    reverse(array, shift);
    reverse(array + shift, size - shift);
    reverse(array, size);
  }
}

void reverse(int* ms, size_t rev)
{
  for (size_t i = 0, j = rev - 1; i < (rev + 1) / 2; i++, j--)
  {
    swapEl(ms[i], ms[j]);
  }
}

void swapEl(int& x, int& y)
{
  int z = 0;
  z = x;
  x = y;
  y = z;
}
