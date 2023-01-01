#include "vector_t.h"
#include <cmath>
dimkashelk::vector_t::vector_t(double x, double y):
  x(x),
  y(y)
{}
dimkashelk::vector_t::vector_t(point_t end, point_t start):
  vector_t(end.x - start.x, end.y - start.y)
{}
dimkashelk::vector_t& dimkashelk::vector_t::operator*=(double k)
{
  x *= k;
  y *= k;
  return *this;
}
double dimkashelk::vector_t::getLength() const
{
  return sqrt(x * x + y * y);
}
