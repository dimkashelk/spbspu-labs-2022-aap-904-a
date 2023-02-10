#include "increaseLineSize.h"
char *increaseSize(char *cstring, size_t capasity, size_t size)
{
  char *newstring = new char[capasity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  return newstring;
}
