#include "createCString.h"
#include "increaseString.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

char* createCString(std::istream& inp, size_t size, size_t capacity)
{
  char* cstring = nullptr;
  try
  {
    cstring = new char[capacity];
  }
  catch (const std::exception&)
  {
    delete[] cstring;
    throw;
  }
  inp >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newStr = new char[capacity + 20];
        newStr = increaseString(cstring, newStr, size);
        delete[] cstring;
        cstring = newStr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    inp >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  if (size <= 1)
  {
    delete[] cstring;
    throw std::logic_error("empty input");
  }
  else
  {
    cstring[size - 1] = '\0';
  }
  return cstring;
}
