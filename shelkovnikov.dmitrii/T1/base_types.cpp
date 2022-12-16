#include "base_types.h"
#include <cmath>
point_t rectangle_t::getLeftDownPoint() const
{
  return point_t(x - width / 2, y - height / 2);
}
double vector_t::getLength() const
{
  return sqrt(x * x + y * y);
}
