#include "readString.h"
#include <stdexcept>
#include <limits>
#include <iostream>
#include "extendString.h"
char *readString(std::istream &inputStr, size_t &in_size)
{
  size_t capacity = 10;
  const size_t max_size = std::numeric_limits< size_t >::max();
  char *newstr = nullptr;
  char *cstring = new char[capacity];
  size_t size = 0;
  inputStr >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      if (capacity >= max_size)
      {
        delete[] cstring;
        throw std::runtime_error("size more than max size");
      }
      else
      {
        try
        {
          newstr = extendString(cstring, size, capacity);
          delete[] cstring;
          cstring = newstr;
          capacity += 20;
        }
        catch (...)
        {
          delete[] cstring;
          throw std::runtime_error("ERROR");
        }
      }
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete[] cstring;
    throw std::runtime_error("Input error");
  }
  in_size = size;
  cstring[size - 1] = '\0';
  return cstring;
}
