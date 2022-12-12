#include <cmath>
#include "extendcstring.hpp"

char * extendCString(char * cstring, size_t & capacity, size_t size)
{
  capacity = static_cast<size_t>(std::ceil(capacity * std::sqrt(2)));
  char * newstr = new char[capacity];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete [] cstring;
  cstring = newstr;
  return cstring;
}
