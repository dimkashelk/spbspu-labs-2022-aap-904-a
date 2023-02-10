#include "string_extension.h"
#include <cstddef>

char* expandString(char* source, size_t oldsize, size_t newsize)
{
  char* newstr = new char[newsize];
  for (auto i = source, j = newstr; i != source + oldsize - 1; ++i, ++j)
  {
    *j = *i;
  }
  return newstr;
}
