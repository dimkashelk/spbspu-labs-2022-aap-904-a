#include "increaseString.h"
#include <cstddef>

char* increaseString(char* string1, const size_t capacity, const size_t size)
{
  char* newStr = new char[capacity + 20];
  for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
