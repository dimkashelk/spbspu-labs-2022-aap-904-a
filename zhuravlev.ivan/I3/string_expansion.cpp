#include "string_expansion.h"
#include <cstring>

void stringExpansion(char* str, size_t new_capacity)
{
  char* new_str = new char[new_capacity];
  std::strcpy(new_str, str);
  delete[] str;
  str = new_str;
  delete[] new_str;
}
