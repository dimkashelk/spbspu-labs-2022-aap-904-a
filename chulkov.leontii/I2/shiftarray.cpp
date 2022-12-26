#include "shiftarray.h"
#include <stdexcept>
#include <cstddef>

void rev(int* arr, const size_t size)
{
  for (size_t i = 0, j = size - 1; i < (size + 1) / 2; i++, j--)
  {
    std::swap(arr[i], arr[j]);
  }
}
void shiftArray(int* arr, const size_t size, const unsigned shift)
{
  size_t trueShift = 0;
  if (size != 0)
  {
    trueShift = shift % size;
    rev(arr, trueShift);
    rev(arr, size - trueShift);
    rev(arr, size);
  }
}
