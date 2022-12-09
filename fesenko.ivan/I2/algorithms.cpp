#include "algorithms.h"

size_t negativeAfterMax(const int *array, size_t size)
{
  int max = 0;
  if (size > 0) {
    max = array[0];
  }
  int count = 0;
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
      count = 0;
    } else if (array[i] < 0) {
      count++;
    }
  }
  return count;
}

void movingElements(int *array, size_t size, size_t m, size_t n)
{
  if (size > n) {
    int movable_element = 0;
    for (size_t i = m; i <= n; i++) {
      movable_element = array[m];
      for (size_t j = m; j < size - 1; j++) {
        array[j] = array[j + 1];
      }
      array[size - 1] = movable_element;
    }
  }
}
