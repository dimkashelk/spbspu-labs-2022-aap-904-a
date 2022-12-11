#include "arraydynamic.h"
#include <stdexcept>
ArrayDynamic::ArrayDynamic(size_t capacity):
  data(new int[capacity])
  //size(0)
{
}
ArrayDynamic::~ArrayDynamic()
{
  delete [] data;
}
