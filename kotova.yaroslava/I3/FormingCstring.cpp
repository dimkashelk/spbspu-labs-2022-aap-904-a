#include "FormingCstring.h"
#include <istream>
#include <cstring>
#include <cstddef>
#include <stdexcept>
char* formingCstring(size_t & size, std::istream& input)
{
  int cnt = 0;
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
      catch (const std::exception& e)
      {
        delete[] cstring;
        throw;
      }
    }
    input >> cstring[size];
    cnt++;
  } while (input && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0')
  {
    delete[] cstring;
    throw std::invalid_argument("Empty string");
  }
  size = cnt;
  return cstring;
}
