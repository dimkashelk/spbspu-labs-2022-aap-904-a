#include "cstring_capacity.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>

char* makeNewCapacityCString(std::cin& in)
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';

  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstring = new char[capacity + 20];
        for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstring;
        newstring = nullptr;
        capacity += 20;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }
    }
    in >> cstring[size];
  }
  while (in && cstring[size++] != '\n');

  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  return cstring;
}
