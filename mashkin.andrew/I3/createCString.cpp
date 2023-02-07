#include "createCString.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

char* createCString(char* string1, char* newStr, size_t size)
{
  for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
