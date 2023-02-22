#include "readString.h"
#include "extendString.h"
#include <stdexcept>
#include <iostream>
char *readString(std::istream &inputStr)
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  inputStr >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *extendedstring = extendString(cstring, size, capacity + 20);
        delete[] cstring;
        cstring = extendedstring;
        extendedstring = nullptr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw std::invalid_argument("ERROR");
      }
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete[] cstring;
    throw std::invalid_argument("Input error");
  }
  if (cstring[0] == '\n' || cstring[0] == '\0')
  {
    delete[] cstring;
    throw std::invalid_argument("Invalid string");
  }
  cstring[size -1] = '\0';
  return cstring;
}
