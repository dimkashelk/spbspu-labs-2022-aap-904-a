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
      char *extendedstring = extendString(cstring, size, capacity + 20);
      delete[] cstring;
      cstring = extendedstring;
      extendedstring = nullptr;
      capacity += 20;
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete[] cstring;
  }
  if (cstring[0] == '\n' || cstring[0] == '\0')
  {
    delete[] cstring;
  }
  cstring[size -1] = '\0';
  return cstring;
}
