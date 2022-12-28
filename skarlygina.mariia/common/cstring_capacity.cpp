#include "cstring_capacity.h"
#include <cstring_capacity_prev.h>
#include <exception>
#include <iostream>
char* makeNewCString(std::istream& input)
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';

  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring = makeNewCapacityCString(cstring, capacity, size);
      }
      catch (const std::exception& e)
      {
        delete[] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');

  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    delete[] cstring;
    throw std::invalid_argument("Error while reading the string");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
