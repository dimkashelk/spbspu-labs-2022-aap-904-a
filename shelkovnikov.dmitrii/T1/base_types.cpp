#include "base_types.h"
#include <cmath>
point_t::point_t():
  x(0.0),
  y(0.0)
{}
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
rectangle_t::rectangle_t(point_t point_1, point_t point_2):
  point((point_1.x + point_2.x) / 2, (point_1.y + point_2.y) / 2),
  width(point_2.x - point_1.x),
  height(point_2.y - point_1.y)
{
  if (point_2.x < point_1.x || point_2.y < point_1.y)
  {
    throw std::logic_error("It isn't rectangle");
  }
}
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
std::istream& operator>>(std::istream &in, point_t &point)
{
  in >> point.x >> point.y;
  return in;
}
std::ostream& operator<<(std::ostream &out, point_t &point)
{
  out << point.x << " " << point.y;
  return out;
}
std::ostream& operator<<(std::ostream &out, rectangle_t &rectangle)
{
  point_t leftDown = rectangle.getLeftDownPoint();
  point_t rightUp = rectangle.getRightUpPoint();
  out << leftDown << " " << rightUp;
  return out;
}
