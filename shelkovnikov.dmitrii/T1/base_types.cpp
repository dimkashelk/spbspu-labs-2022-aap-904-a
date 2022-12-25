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
point_t &point_t::operator=(const point_t point)
{
  x = point.x;
  y = point.y;
  return *this;
}
rectangle_t::rectangle_t(double x1, double y1, double x2, double y2):
  point((x1 + x2) / 2, (y1 + y2) / 2),
  width(x2 - x1),
  height(y2 - y1)
{}
rectangle_t::rectangle_t(point_t point, double width, double height):
  point(point),
  width(width),
  height(height)
{}
point_t rectangle_t::getLeftDownPoint() const
{
  return point_t(point.x - width / 2, point.y - height / 2);
}
point_t rectangle_t::getRightUpPoint() const
{
  return point_t(point.x + width / 2, point.y + height / 2);
}