#include "increaseLineSize.h"
char *increaseSize(const char *cstring, size_t &capasity, size_t &size, char *newstring)
{
  char *j = newstring;
  for (const char *i = cstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capasity++;
  return newstring;
}
