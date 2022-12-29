#include "extended_string.h"
#include <cstring>

char* makeExtendedString(char* cstring, size_t& capacity)
{
  char* newstring = new char[capacity + 20];
  cstring[capacity - 1] = '\0';
  std::strcpy(newstring, cstring);
  delete[] cstring;
  cstring = newstring;
  newstring = nullptr;
  capacity += 20;
  return cstring;
}
