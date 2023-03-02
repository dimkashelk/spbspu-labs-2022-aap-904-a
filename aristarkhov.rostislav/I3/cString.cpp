#include "cString.h"

char* increaseSize(const char* new_source, size_t capacity, size_t size)
{
  char* dupStr = new char[capacity + 10];
  char* j = dupStr;
  for (const char* i = new_source; i != new_source + size; ++i, ++j)
  {
    *j = *i;
  }
  return dupStr;
}
