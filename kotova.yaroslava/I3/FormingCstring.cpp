#include "FormingCstring.h"
#include <istream>
#include <iostream>
#include <cstring>
#include <cstddef>
char* formingCstring(char* cstring, size_t& capacity, std::istream& input)
{
  cstring[capacity - 1] = '\0';
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring[capacity - 1] = '\0';
        char* newstr = new char[capacity + 20];
        newstr [capacity+19] = '\0';
        if( cstring[capacity - 1] = '\0')
        {
          strcpy(newstr, cstring);
        }
        else
        {
          break;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  cstring[size] = '\0';
  return cstring;
}
