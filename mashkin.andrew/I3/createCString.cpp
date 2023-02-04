#include <iostream>
#include <stdexcept>
#include "createCString.h"

char* createCString()
{
  size_t capacity = 10;
  char* cString = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newStr = new char[capacity + 20];
        for (char* i = cString, *j = newStr; i != cString + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cString;
        cString = newStr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cString;
        throw;
      }
    }
    std::cin >> cString[size];
  } while (std::cin && cString[size++] != '\n');
  if (size <= 1)
  {
    delete[] cString;
    throw std::logic_error("empty input");
  }
  else
  {
    cString[size - 1] = '\0';
  }
  return cString;
}
