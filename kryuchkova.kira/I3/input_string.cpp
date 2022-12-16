#include "input_string.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>

char *input_string(char *cstring)
{
  size_t capacity = 10;
  size_t size = 0;

  std::cin >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
      char *newstr = new char[capacity + 20];
      for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
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

  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\n')
  {
    throw std::invalid_argument("empty string");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
