#include "extend_string.h"
#include <iostream>
#include <stdexcept>
#include "golden_ratio.h"

char *extendString(char* str_1, size_t & capacity_1, size_t size_1)
{
  size_t newCapacity = goldenRatio(capacity_1);
  if (newCapacity < size_1)
  {
    throw std::invalid_argument("bruh");
  }

  char* newstr = new char[newCapacity];
  auto* i = str_1;
  auto* j = newstr;
  while (i != str_1 + size_1)
  {
    *(j++) = *(i++);
  }
  delete [] str_1;
  str_1 = newstr;
  capacity_1 = newCapacity;
  return str_1;
}

