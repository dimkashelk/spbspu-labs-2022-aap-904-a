#include "increaseString.h"
#include <cstddef>

char* increaseString(const char* string1, const size_t capacity, const size_t size, const size_t increaseCapacity)
{
  char* newStr = new char[capacity + increaseCapacity];
  for (const char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
