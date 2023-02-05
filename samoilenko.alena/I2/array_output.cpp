#include "array_output.h"
#include <iostream>
#include <cstddef>
void outputAnArray(const int* array, size_t size, std::ostream & out)
{
  for (size_t i = 0; i < size; i++)
  {
    out << array[i] << ' ';
  }
}
