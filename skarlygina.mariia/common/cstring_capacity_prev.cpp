#include "cstring_capacity_prev.h"

char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size)
{
  char* newstring = new char[capacity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
      *j = *i;
  }
  delete[] cstring;
  cstring = newstring;
  newstring = nullptr;
  capacity += 20;
  return cstring;
}
