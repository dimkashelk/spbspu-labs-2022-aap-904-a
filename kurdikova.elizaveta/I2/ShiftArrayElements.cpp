#include "ShiftArrayElements.h"

void shiftArrayElements(int* arr, size_t size, size_t shift)
{
  int extraArr[size];
  for (size_t i = 0; i < size; ++i) {
    extraArr[i] = arr[i];
  }
  for (size_t i = 0; i < size; ++i) {
    arr[(i + shift) % size] = extraArr[i];
  }
}
