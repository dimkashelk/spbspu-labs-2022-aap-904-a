#include "extendcstring.hpp"
#include <cstring>

char *extendCString(char *c_string, size_t &capacity)
{
  char *newstr = new char[capacity + 10];
  c_string[capacity - 1] = '\0';
  std::strcpy(newstr, c_string);
  delete[] c_string;
  c_string = newstr;
  capacity += 10;

  return c_string;
}
