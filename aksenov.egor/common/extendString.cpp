#include "extendString.h"
#include <limits>
#include <stdexcept>
char *extendString(char *cstring, size_t size, size_t capacity, size_t increaseCapacity)
{
  const size_t max_size_t = std::numeric_limits< size_t >::max();
  char *newstring = new char[capacity + increaseCapacity];
  char *j = newstring;
  if (size = capacity)
  {
    if (capacity == max_size_t || max_size_t <= capacity + increaseCapacity)
    {
      delete[] newstring;
      throw std::runtime_error("String is too long");
    }
    else
    {
      for (const char *i = cstring; i != cstring + size; ++i, ++j)
      {
        *j = *i;
      }
    }
  return newstring;
}
