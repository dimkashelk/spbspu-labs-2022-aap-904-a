#include <stdexcept>
#include "dynamicArray.h"
turkin::Array::Array(size_t size_):
  data(new int[size_]),
  size(0)
{}

turkin::Array::~Array()
{
  delete [] data;
}
