#include "PrintArray.hpp"
#include <ostream>
#include <cstddef>

void print_array(const int* arr, size_t size, std::ostream& streamOut)
{
  for (size_t i = 0; i < size; i++)
  {
    streamOut << arr[i] << " ";
  }
}