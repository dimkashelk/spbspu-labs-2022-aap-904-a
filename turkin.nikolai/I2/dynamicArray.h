#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cstddef>
namespace turkin
{
  struct Array
  {
    explicit Array(size_t cap):
      data(new int[cap]),
      size(0),
      capacity(cap)
    {}

    ~Array();

    int * data;
    size_t size;
    size_t capacity;
  };

  int * extend(const int * array, size_t size, size_t newCapacity);
}
#endif
