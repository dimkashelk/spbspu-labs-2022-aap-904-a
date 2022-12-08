#include "charArray.h"
#include <limits>
#include <stdexcept>

turkin::CharArray::CharArray(size_t cap):
  data(new char[cap]),
  size(0),
  capacity(cap)
{}

turkin::CharArray::~CharArray()
{
  delete [] data;
}

void turkin::extend(turkin::CharArray & array, size_t addition)
{
  if (array.capacity + addition == std::numeric_limits< size_t >::max())
  {
    throw std::overflow_error("out of size\n");
  }
  char * extendArray = new char[array.capacity + addition];
  for (size_t i = 0; i < array.size; i++)
  {
    extendArray[i] = array.data[i];
  }
  delete [] array.data;
  array.capacity = array.capacity + addition;
  array.data = extendArray;
}
