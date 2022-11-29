#include "array.hpp"
#include <stdexcept>
#include <limits>
#include <stddef.h>

Array::Array(size_t cap):
  data(new int[cap]),
  size(0),
  cap(cap)
{}

Array::~Array()
{
  delete [] data;
}

int findMax(const int* arr, size_t size, int lowBound, int highBound)
{
  const int minInt = std::numeric_limits< int >::min();
  int max = minInt;
  for (size_t i = 0; i < size; i++) {
    if ((lowBound < arr[i]) && (arr[i] < highBound) && (arr[i] > minInt)) {
      max = arr[i];
      if (max == highBound - 1) {
        break;
      }
    }
  }
  if (max == minInt) {
    throw std::logic_error("Max value could not be found in array");
  }
  return max;
}
