#include "extendcstring.hpp"

char * extendCString(char * cstring, size_t & capacity, size_t size)
{
  char * newstr = new char[capacity + 20];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete [] cstring;
  cstring = newstr;
  capacity += 20;
  return cstring;
}
