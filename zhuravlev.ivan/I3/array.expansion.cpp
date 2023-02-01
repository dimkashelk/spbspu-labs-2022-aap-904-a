#include "array.expansion.h"
#include <cstring>

char arrayExpansion(const char* str, size_t new_capacity)
{
  char* new_str = new char[new_capacity];
  strcpy(new_str, str);
  delete [] str;
  str = new_str;
  return *str;
}