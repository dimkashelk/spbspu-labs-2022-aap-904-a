#include "outputarray.hpp"
#include <iostream>
#include <cstddef>
int outputArray(int array[], size_t size)
{
  std::cout << "Sort array: ";
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
