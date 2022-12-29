#include "ArrayOperations.h"
#include <iostream>
#include <limits>
#include <exception>

void printArray(const int* arr, size_t size)
{
  size_t last_id = size - 1;
  std::cout << "{ ";
  for (size_t i = 0; i < last_id; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[last_id] << " }";
}

void randomizeArray(int* arr, size_t size)
{
  std::srand(time(nullptr));
  for (size_t i = 0; i < size; i++) {
    arr[i] = std::rand();
  }
}

void shiftByIndexes(int* arr, size_t size, size_t n, size_t m)
{
  if (m > size) {
    throw std::runtime_error("index out of range");
  }
  if (m < n) {
    throw std::runtime_error("left index cannot be greater than right");
  }
  size_t offset = size - m;
  size_t offset1 = m - n;
  int curr = arr[n];
  int temp = 0;
  size_t i = n;
  size_t j = 0;

  while (true) {
    if (i >= n && i < m) {
      j = i + offset;
    }
    else {
      j = i - offset1;
    }
    temp = arr[j];
    arr[j] = curr;
    curr = temp;
    i = j;

    if (i == n) {
      break;
    }
  }
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
