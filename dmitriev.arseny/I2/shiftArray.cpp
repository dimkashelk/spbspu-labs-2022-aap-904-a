#include "shiftArray.h"
#include <stdexcept>
#include <cstddef>

void shiftArray(int* array, const size_t size, const size_t shift)
{
  if (int(shift) < 0)
  {
    throw::std::invalid_argument("incorrect shift");
  }
  reverse(array, shift);
  reverse(array + shift, size - shift);
  reverse(array, size);
}

void reverse(int* ms, size_t rev)
{
  for (size_t i = 0, j = rev - 1; i < (rev + 1) / 2; i++, j--)
  {
    std::swap(ms[i], ms[j]);
  }
}
