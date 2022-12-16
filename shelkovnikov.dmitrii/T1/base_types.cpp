#include "base_types.h"
#include <cmath>
point_t::point_t(double x, double y):
  x(x),
  y(y)
{}
point_t::point_t(const point_t &point):
  x(point.x),
  y(point.y)
{}
point_t rectangle_t::getLeftDownPoint() const
{
  return point_t(x - width / 2, y - height / 2);
}
vector_t &vector_t::operator*=(double k)
{
  x *= k;
  y *= k;
  return this;
}
double vector_t::getLength() const
{
  return sqrt(x * x + y * y);
}
