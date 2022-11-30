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
  delete [] extendBuffer;
}

bool turkin::Array::extend()
{
  if (capacity + 10 == std::numeric_limits< size_t >::max())
  {
    return false;
  }
  extendBuffer = new char[capacity + 10];
  capacity = capacity + 10;
  for (size_t i = 0; i < size; i++)
  {
    extendBuffer[i] = data[i];
  }
  data = extendBuffer;
  extendBuffer = nullptr;
  return true;
}

bool turkin::Array::push(std::istream & cin)
{
  char buffer;
  cin >> buffer;
  return push(buffer);
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
  data[size] = symbol;
  size++;
  return true;
}
