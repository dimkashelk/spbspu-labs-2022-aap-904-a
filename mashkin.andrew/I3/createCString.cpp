#include <iostream>
#include <stdexcept>
#include "createCString.h"

char* createCString()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstr = new char[capacity + 20];
        for (char* i = cstring, *j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
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
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  if (!std::cin && size == 1)
  {
    delete[] cstring;
    throw std::logic_error("empty input");
  }
  else
  {
    cstring[size] = '\0';
  }
  return cstring;
}
