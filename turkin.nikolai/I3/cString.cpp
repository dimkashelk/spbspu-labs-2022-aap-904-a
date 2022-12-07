#include "cString.h"
#include <limits>
#include <stdexcept>

turkin::String::String(size_t cap):
  data(new char[cap]),
  size(0),
  capacity(cap)
{}

turkin::String::~String()
{
  delete [] data;
}

void turkin::String::extend()
{
  if (capacity + extendSize == std::numeric_limits< size_t >::max())
  {
    throw std::overflow_error("out of size\n");
  }
  capacity += extendSize;
  extendBuffer = new char[capacity];
  for (size_t i = 0; i < size; i++)
  {
    extendBuffer[i] = data[i];
  }
  delete [] data;
  data = extendBuffer;
}

void turkin::String::push(char symbol)
{
  if (size >= capacity)
  {
    try
    {
      extend();
    }
    catch (...)
    {
      throw std::overflow_error("out of size\n");
    }
  }
  data[size++] = symbol;
}
