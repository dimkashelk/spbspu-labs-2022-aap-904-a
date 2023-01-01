#include "base_types.h"
#include <cmath>
dimkashelk::point_t::point_t():
  x(0.0),
  y(0.0)
{}
dimkashelk::point_t::point_t(double x, double y):
  x(x),
  y(y)
{}
dimkashelk::rectangle_t::rectangle_t(point_t point_1, point_t point_2):
  point((point_1.x + point_2.x) / 2, (point_1.y + point_2.y) / 2),
  width(point_2.x - point_1.x),
  height(point_2.y - point_1.y)
{
  if (point_2.x < point_1.x || point_2.y < point_1.y)
  {
    throw std::logic_error("It isn't rectangle");
  }
}
dimkashelk::rectangle_t::rectangle_t(point_t point, double width, double height):
  point(point),
  width(width),
  height(height)
{
  if (width <= 0 || height <= 0)
  {
    throw std::logic_error("It isn't rectangle");
  }
}
