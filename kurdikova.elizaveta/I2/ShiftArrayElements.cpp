#include <cstddef>
#include "ShiftArrayElements.h"

bool shiftArrayElements(int* arr, size_t size, size_t shift)
{
  if (shift >= size) {
    return false;
  }
  int extraArr[size];
  for (size_t i = 0; i < size; ++i) {
    extraArr[i] = arr[i];
  }
  for (size_t i = 0; i < size; ++i) {
    arr[(i + shift) % size] = extraArr[i];
  }
  return true;
}
