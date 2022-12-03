#include "shiftArray.h"
#include <stdexcept>

void shiftArray(int* array, const int size, const int shift)
{
  if (shift > size)
  {
    throw::std::invalid_argument("incorrect shift");
  }
  int* arrDuplicate = new int[size];
  for (int i = 0; i < size; i++)
  {
    arrDuplicate[i] = array[(i + shift) % size];
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = arrDuplicate[i];
  }

  delete[] arrDuplicate;
}
