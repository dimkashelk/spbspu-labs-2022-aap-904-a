#include "shiftarray.h"
#include <stdexcept>
#include <cstddef>

void shiftArray(int* arr, const size_t size, const unsigned shift)
{
  if (size == 0)
  {
    return;
  }
  int* arrDuplicate = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    arrDuplicate[(i + shift) % size] = arr[i];
  }
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = arrDuplicate[i];
  }
  delete[] arrDuplicate;
}
