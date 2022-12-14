#include "PrintArray.hpp"
#include <ostream>
#include <cstddef>

void print_array(std::ostream& streamOut, const int* arr, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    streamOut << arr[i] << " ";
  }
  streamOut << arr[size - 1] << '\n';
}
