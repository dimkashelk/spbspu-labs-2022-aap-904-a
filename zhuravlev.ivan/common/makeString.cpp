#include "makeString.h"
#include "string_expansion.h"
#include <iostream>
#include <stdexcept>

char* makeCstring(std::istream& input)
{
  size_t capacity = 10;
  size_t new_capacity = 0;
  char* cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\n';
  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      try
      {
        cstring[size] = '\0';
        new_capacity += 20;
        char* new_str = nullptr;
        char* prev_cstring = cstring;
        new_str = stringExpansion(cstring, capacity, new_capacity);
        delete[] prev_cstring;
        cstring = new_str;
        capacity += new_capacity;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cstring;
        throw;
      }
      input >> cstring[size];
    }
  }
  while (input && cstring[size++] != '\n');
  if (cstring[0] == '\n' || size == 0)
  {
    delete[] cstring;
    throw;
  }
  cstring[size - 1] = '\0';
  return cstring;
}
