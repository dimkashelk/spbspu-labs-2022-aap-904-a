#include "cstring_capacity_prev.h"
#include <cstring>
char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size)
{
  char* newstring = new char[capacity + 20];
  strcpy (newstring, cstring);
  cstring = newstring;
  capacity += 20;
  return cstring;
}
