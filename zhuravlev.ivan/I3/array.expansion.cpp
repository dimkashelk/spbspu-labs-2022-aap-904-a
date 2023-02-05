#include "array.expansion.h"
#include <cstring>

char* arrayExpansion(const char* str, size_t new_capacity)
{
  char* new_str = new char[new_capacity + 20];
  strcpy(new_str, str);
  new_capacity += 20;
  return new_str;
}
