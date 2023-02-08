#include "increaseString.h"
#include <cstddef>

char* increaseString(char* string1, char* newStr, size_t size)
{
  for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
