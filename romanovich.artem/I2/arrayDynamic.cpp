#include "arrayDynamic.h"
#include <stdexcept>
ArrayDynamic::ArrayDynamic(size_t size) :
  data(new int[size]),
  size(0)
{
}
ArrayDynamic::~ArrayDynamic()
{
  delete [] data;
}
