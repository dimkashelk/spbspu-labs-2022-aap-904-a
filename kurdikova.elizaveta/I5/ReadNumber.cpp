#include "ReadNumber.h"
#include <iostream>
#include <cstddef>
#include <cstring>
#include <valarray>

char* readNumber(char* number)
{
  size_t size = 0;
  size_t capacity = 4;
  number = new char[capacity];
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      capacity *= 2;
      char* newstr = new char[capacity];
      number[size] = '\0';
      std::strcpy(newstr, number);
      delete[] number;
      number = newstr;
    }
    std::cin >> number[size++];
  }
  while (std::cin && number[size - 1] != '\n');
  number[size - 1] = '\0';
  if (size <= 1)
  {
    return nullptr;
  }
  return number;
}
