#include "FormingCstring.h"
#include <istream>
#include <iostream>
#include <cstring>
#include <cstddef>
char* formingCstring(char* cstring, size_t& capacity, std::istream& input)
{
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        char* i = 0;
        char* j = 0;
        strcpy(i, cstring);
        strcpy(j, newstr);
        while(i != cstring + size)
        {
          ++i;
          ++j;
          *j = *i;
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
