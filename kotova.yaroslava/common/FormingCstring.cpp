#include "FormingCstring.h"
#include <istream>
#include <cstddef>
#include <cstring>
#include <stdexcept>
char* formingCstring(std::istream& input)
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstring = new char[capacity];
  cstring[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstr = new char[capacity + 20];
        cstring[capacity - 1] = '\0';
        std::strcpy(newstr, cstring);
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
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
  cstring[size - 1] = '\0';
  return cstring;
}