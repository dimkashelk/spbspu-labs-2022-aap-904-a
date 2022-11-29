#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

struct Array {
  int* data;
  size_t size;
  size_t cap;

  Array(size_t cap);

  ~Array();
};

int findMax(const int* arr, size_t size, int lowBound, int highBound);

#endif
