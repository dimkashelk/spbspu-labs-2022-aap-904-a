#include "ArrayOperations.h"
#include <iostream>

void shiftByIndexes(int* arr, size_t size, size_t n, size_t m)
{
  size--;
  size_t offset = m - n + 1;
  int* temp = new int[size]{0};

  int j = 0;
  for (size_t i = n - 1; i < m; i++) {
    temp[j] = arr[i];
    j++;
  }
  for (size_t i = m; i <= size; i++) {
    arr[i - offset] = arr[i];
  }
  j = 0;
  for (size_t i = size - offset + 1; i <= size; i += 1) {
    arr[i] = temp[j];
    j++;
  }

  delete[] temp;
}