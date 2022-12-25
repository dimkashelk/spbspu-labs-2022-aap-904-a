#include "inputstring.h"
#include "extendstring.h"
#include <iostream>
#include <stdexcept>
char * inputString(std::istream & inputStr)
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
      	cstring = extendString(cstring, capacity, size);
      }
      catch (...)
      {
        delete[] cstring;
        throw std::invalid_argument("Error while extending string.");
      }
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete [] cstring;
  	throw std::invalid_argument("Input incorrect.");
  }
  if (cstring[0] == '\n' || cstring[0] == '\0')
  {
  	delete [] cstring;
  	throw std::invalid_argument("No string provided.");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
