#include "extendstring.h"
#include <stdexcept>
char *extendString(char *cstring, size_t size, size_t capacity)
{
  if (size < capacity)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  char *newstr = new char[capacity];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete[] cstring;
  cstring = newstr;
  return cstring;
}
