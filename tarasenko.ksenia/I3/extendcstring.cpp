#include "extendcstring.hpp"

char * extendCString(char * cstring, size_t & capacity, size_t size)
{
  double cap = static_cast<double>(capacity);
  cap *= std::sqrt(2);
  cap = std::ceil(cap);
  capacity = static_cast<size_t>(cap);
  char * newstr = new char[capacity];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete [] cstring;
  cstring = newstr;
  return cstring;
}
