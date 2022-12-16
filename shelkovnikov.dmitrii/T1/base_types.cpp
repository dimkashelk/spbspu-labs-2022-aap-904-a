#include "base_types.h"
#include <cmath>
double vector_t::getLength() const
{
  return sqrt(x * x + y * y);
}
