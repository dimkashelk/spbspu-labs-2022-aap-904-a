#include "outputarray.h"
#include <iostream>

std::ostream& outputArray(std::ostream& out, const int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    out << arr[i] << '\t';
  }
  return out;
}
