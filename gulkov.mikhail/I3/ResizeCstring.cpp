#include "ResizeCstring.hpp"
#include <cstddef>

char *check_and_resize(char *arr, size_t &size, size_t &capacity)
{
  if (size == capacity)
  {
    char *newarr = new char[capacity + 20];
    for (auto k = arr, t = newarr; k != arr + size; ++k, ++t)
    {
      *t = *k;
    }
    delete[] arr;
    arr = newarr;
    capacity += 20;
  }

  return arr;
}
