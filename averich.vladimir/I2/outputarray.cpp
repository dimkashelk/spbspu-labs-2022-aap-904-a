#include "outputarray.hpp"
#include <iostream>
#include <cstddef>
int outputArray(const int array[], size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << " " << array[i];
  }
  return array[size];
}
