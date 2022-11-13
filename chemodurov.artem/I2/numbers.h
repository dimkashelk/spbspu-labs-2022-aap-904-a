#ifndef NUMBERS_H
#define NUMBER_S
#include <stddef.h>

namespace chemodurov
{
  struct Array
  {
    Array(size_t cap):
     data(new int[cap]),
     size(0),
     capacity(cap)
    {}

    ~Array()
    {
      delete [] data;
    }

    int * data;
    size_t size;
    size_t capacity;
  };
  int * extendDynArray(const int * arr, size_t size, size_t newcapacity);
  unsigned int countMaxDecreasing(int * arr, size_t size);
  unsigned int countDivisible(int * arr, size_t size, int divider);
}
#endif
