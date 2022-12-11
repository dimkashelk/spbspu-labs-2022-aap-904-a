#include "task7.h"

int shiftArrayElements(int* arr, int size, int shift)
{
  if (shift >= size) {
    return 1;
  }
  int extraArr[size];
  for (int i = 0; i < size; ++i) {
    extraArr[i] = arr[i];
  }
  for (int i = 0; i < size; ++i) {
    arr[(i + shift) % size] = extraArr[i];
  }
  return 0;
}
