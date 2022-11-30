#include "cString.h"
#include <stdexcept>
#include <limits>

turkin::Array::Array(size_t cap)
{
  data = new char[cap];
  size = 0;
  capacity = cap;
}

turkin::Array::~Array()
{
  delete [] data;
}

bool turkin::Array::extend()
{
  if (capacity + extendSize == std::numeric_limits< size_t >::max())
  {
    return false;
  }
  capacity += extendSize;
  extendBuffer = new char[capacity];
  for (size_t i = 0; i < size; i++)
  {
    extendBuffer[i] = data[i];
  }
  delete [] data;
  data = extendBuffer;
  extendBuffer = nullptr;
  return true;
}

bool turkin::Array::push(char symbol)
{
  if (size >= capacity)
  {
    if (!extend())
    {
      return false;
    }
  }
  data[size++] = symbol;
  return true;
}
