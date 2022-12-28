#include "cstring_capacity.h"
#include <exception>
#include <iostream>
#include <cstring>
#include <memory>
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
        auto newstring = std::make_unique< char[] >(capacity + 20);
        std::strcpy(newstring.get(), cstring);
        delete[] cstring;
        cstring = newstring;
        newstring = nullptr;
        capacity += 20;
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
