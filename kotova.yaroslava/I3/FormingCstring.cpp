#include "FormingCstring.h"
#include <istream>
#include <iostream>
#include <cstring>
#include <cstddef>
char* formingCstring(std::istream & input)
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        char* i,*j;
        strcpy(i, cstring);
        strcpy(j, newstr);
        while(i != cstring + size)
        {
          *j = *i;
          ++i;
          ++j;
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
  return cstring;
}
