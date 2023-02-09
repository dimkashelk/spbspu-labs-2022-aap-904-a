#include "increaseString.h"
#include <cstddef>

char* increaseString(char* string1, const size_t newCapacity, const size_t size)
{
  char* newStr = new char[newScapacity];
  for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
