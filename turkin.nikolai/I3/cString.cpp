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
  if (capacity + 10 == std::numeric_limits< size_t >::max())
  {
    return false;
  }
  char * newData = new char[capacity + 10];
  for (size_t i = 0; i < size; i++)
  {
    newData[i] = data[i];
  }
  data = newData;
  return true;
}

bool turkin::Array::push(std::istream & cin)
{
  cin >> buffer;
  return push(buffer);
}

bool turkin::Array::push(char symbol)
{
  if (size == capacity)
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
