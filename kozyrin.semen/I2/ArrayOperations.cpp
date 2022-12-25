#include "ArrayOperations.h"
#include <iostream>
#include <limits>

void printArray(int* arr, size_t size)
{
  size--;
  std::cout << "Processed array: { ";
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[size] << " }";
}

void shiftByIndexes(int* arr, size_t size, size_t n, size_t m)
{
  size--;
  size_t offset = m - n + 1;
  int* temp = new int[size]{0};

  int j = 0;
  for (size_t i = n; i <= m; i++) {
    temp[j] = arr[i];
    j++;
  }
  for (size_t i = m + 1; i <= size; i++) {
    arr[i - offset] = arr[i];
  }
  j = 0;
  for (size_t i = size - offset + 1; i <= size; i++) {
    arr[i] = temp[j];
    j++;
  }

  delete[] temp;
}

int maxEven(const int* arr, size_t size)
{
  int max = std::numeric_limits< int >::min();

  for (size_t i = 1; i < size; i += 2) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}
