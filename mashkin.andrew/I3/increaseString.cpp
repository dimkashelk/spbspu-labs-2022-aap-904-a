#include "increaseString.h"
#include <cstddef>

char* increaseString(char* string1, char* newStr, const size_t size)
{
  for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  char* varStr = string1;
  string1 = newStr;
  newStr = varStr;
  return string1;
}
