#include "FormingCstring.h"
#include <istream>
#include <cstring>
#include <cstddef>
#include <stdexcept>
char* formingCstring(size_t & size, std::istream& input)
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  cstring[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      try
      {
        cstring[size] = '\0';
        char* newstr = new char[capacity + 10];
        std::strcpy(newstr, cstring);
        delete[] cstring;
        cstring = newstr;
        capacity += 10;
      }
      catch (const std::exception& e)
      {
        delete[] cstring;
        throw;
      }
    }
    input >> cstring[size];
  } while (input && cstring[size++] != '\n');
  if (cstring[0] == '\0')
  {
    delete[] cstring;
    throw std::invalid_argument("Empty string");
  }
  cstring[capacity - 1] = '\0';
  return cstring;
}
