#include "algorithms.h"
#include <iostream>

size_t negativeAfterMax(const int *array, size_t size)
{
  int max = array[0], maxi = 0;
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
      maxi = i;
    }
  }
  int count = 0;
  for (size_t i = maxi + 1; i < size; i++) {
    if (array[i] < 0) {
      count++;
    }
  }
  return count;
}

void movingElements(int *array, size_t size)
{
  size_t m = 2, n = 4;
  if (size <= n) {
    std::cerr << "Not ehough array size\n";
  } else {
    size_t mov_el_size = n - m + 1;
    int* moving_elements = new int[mov_el_size];
    for (size_t i = m; i <= n; i++) {
      moving_elements[i - m] = array[i];
    }
    for (size_t i = n + 1; i < size; i++) {
      array[i - mov_el_size] = array[i];
    }
    for (size_t i = size - mov_el_size; i < size; i++) {
      array[i] = moving_elements[i - size + mov_el_size];
    }
    delete[] moving_elements;
  }
}
