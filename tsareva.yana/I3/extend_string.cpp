#include <iostream>
#include <limits>
#include "extend_string.h"
#include <stdexcept>
#include "golden_ratio.h"

char *extendString(char* str_1, size_t & capacity_1, size_t size_1){
  size_t max_size_t = std::numeric_limits< size_t >::max();
  if (( max_size_t - (goldenRatio(capacity_1) - capacity_1)) <= capacity_1)
  {
    throw std::invalid_argument("to much");
  }
  else
  {
    capacity_1 = goldenRatio(capacity_1);
  }
  if (capacity_1 < size_1)
  {
    throw std::invalid_argument("bruh");
  }
  char* newstr = new char[capacity_1];
  auto* i = str_1;
  auto* j = newstr;
  while (i != str_1 + size_1)
  {
    *(j++) = *(i++);
  }
  delete [] str_1;
  str_1 = newstr;
  return str_1;
}

