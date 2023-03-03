#include "my_ext_String.h"
#include <cstring>

char* extendMyString(const char* my_string, size_t &capacity)
{
  char* newstr = new char[capacity + 10];
  std::strcpy(newstr, my_string);
  capacity += 10;

  return newstr;
}
