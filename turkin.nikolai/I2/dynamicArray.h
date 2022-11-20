#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cstddef>
namespace turkin
{
  struct Array
  {
    explicit Array(size_t size_):
      data(new int[size_]),
      size(0)
    {}

    ~Array();

    int * data;
    size_t size;
  };
}
#endif
