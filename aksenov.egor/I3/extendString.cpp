#include "extendString.h"
#include <stdexcept>
char *extendString(char *cstring, size_t size, size_t capacity)
{
  if (capacity < size)
  {
    throw std::invalid_argument("unreal");
  }
  char *newstring = new char[capacity];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  return newstring;
}
