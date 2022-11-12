#include "dynamicArray.h"
#include <stdexcept>
#include <cstddef>
turkin::Array::~Array()
{
  delete [] data;
}

int * turkin::extend(const int * array, size_t size, size_t newCapacity)
{
  if (size > newCapacity)
  {
    throw std::invalid_argument("new capacity < size");
  }
  int * newArray = new int[newCapacity];
  for (size_t i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
  return newArray;
}
