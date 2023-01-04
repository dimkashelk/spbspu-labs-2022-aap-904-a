#include "extendcstring.hpp"

char *extendCString(size_t &capacity)
{
  char *newstr = new char[capacity + 10];
  capacity += 10;

  return newstr;
}
