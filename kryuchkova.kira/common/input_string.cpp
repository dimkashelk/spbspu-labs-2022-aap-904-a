#include "input_string.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <cstring>

char *inputString(char *cstring, size_t &capacity)
{
  size_t size = 0;
  std::cin >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 20];
        newstr[capacity + 20] = '\0';
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;

        strcpy(cstring, newstr);
        //cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  capacity = size;
  return cstring;
}
