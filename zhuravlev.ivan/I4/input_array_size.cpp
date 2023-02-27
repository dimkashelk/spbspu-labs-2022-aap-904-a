#include "input_array_size.h"

bool inputArraySize(size_t nRows, size_t nColomns)
{
  if ((nRows <= 0) || (nColomns <= 0))
  {
    return false;
  }
  if (nRows != nColomns)
  {
    return false;
  }
  return true;
}
