#include "extendcstring.hpp"

char * extendCString(char * cstring, size_t & capacity, size_t size)
{
  capacity *= std::sqrt(2);
  char * newstr = new char[capacity];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete [] cstring;
  cstring = newstr;
  return cstring;
}
