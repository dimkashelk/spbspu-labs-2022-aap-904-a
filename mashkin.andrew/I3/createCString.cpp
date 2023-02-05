#include "createCString.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

char* createCString(char* string1, size_t capacity, size_t size)
{
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newStr = new char[capacity + 20];
        for (char* i = string1, *j = newStr; i != string1 + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] string1;
        string1 = newStr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] string1;
        throw;
      }
    }
    std::cin >> string1[size];
  } while (std::cin && string1[size++] != '\n');
  if (size <= 1)
  {
    delete[] string1;
    throw std::logic_error("empty input");
  }
  else
  {
    string1[size - 1] = '\0';
  }
  return string1;
}
