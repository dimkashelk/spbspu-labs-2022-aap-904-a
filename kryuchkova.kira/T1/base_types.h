#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace kryuchkova
{
  struct point_t
  {
    double x;
    double y;
    point_t(double x, double y):
    x(x),
    y(y)
    {}
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
    rectangle_t(double width, double height, point_t pos):
    width(width),
    height(height),
    pos(pos)
    {}
  };
}

#endif
