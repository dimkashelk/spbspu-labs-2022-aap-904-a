#include "FormingCstring.h"
#include <istream>
#include <cstring>
#include <cstddef>
char* formingCstring(size_t & size, std::istream& input)
{
  size_t capacity = 10;
  cstring[capacity - 1] = '\0';
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstr = new char[capacity + 10];
        cstring[capacity - 1] = '\0';
        std::strcpy(newstr, cstring);
        delete [] cstring;
        cstring = newstr;
        capacity += 10;
      }
      catch (...)
      {
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  size = 10;
  return cstring;
}
