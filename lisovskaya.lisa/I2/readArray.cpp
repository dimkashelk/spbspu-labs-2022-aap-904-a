#include "readArray.h"
#include <stdexcept>
#include <iostream>
int *readArray(std::istream &in, size_t line, int *array3)
{
  for (size_t i = 0; i < line; ++i)
  {
    in >> array3[i];
    if (!in)
    {
      throw std::length_error("File error");
    }
  }
  return array3;
}
