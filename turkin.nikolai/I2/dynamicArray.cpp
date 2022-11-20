#include "dynamicArray.h"
#include <stdexcept>
turkin::Array::~Array()
{
  delete [] data;
}
