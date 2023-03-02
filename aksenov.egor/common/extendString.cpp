#include "extendString.h"
char *extendString(char *cstring, size_t size, size_t capacity, size_t increaseCapacity)
{
  char *newstring = new char[capacity + increaseCapacity];
  char *j = newstring;
  for (const char *i = cstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  return newstring;
}
