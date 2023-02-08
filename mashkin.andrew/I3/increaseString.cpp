#include "increaseString.h"
#include <cstddef>

char* increaseString(const char* string1, const size_t capacity, const size_t size)
{
  char* newStr = new char[capacity + 20];
  for (const char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
