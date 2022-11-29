#include "PrintArray.hpp"
#include <iostream>
#include <cstddef>

void print_array(const int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
}
