#include "ResizeCstring.hpp"
#include <cstddef>
#include <stdexcept>

char *check_and_resize(char *arr, unsigned int &size, unsigned int &capacity)
{
  if (size == capacity)
  {
    try
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
    catch (const std::bad_alloc &e)
    {
      throw std::runtime_error("Error while resizing array!");
    }
  }

  return arr;
}
