#include "string_expansion.h"
#include <cstring>

char* stringExpansion(char* str, size_t new_capacity)
{
  char* new_str = new char[new_capacity];
  for (char* i = str, *j = new_str; *i != '\0'; ++i, ++j)
  {
    *j = *i;
  }
  return new_str;
}
