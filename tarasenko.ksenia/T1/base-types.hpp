#ifndef BASETYPES_HPP
#define BASETYPES_HPP

struct point_t
{
  double x_, y_;
  point_t(double x, double y);
}

struct rectangle_t
{
  double width_, height_;
  point_t pos_;
  rectangle_t(double x1, double y1, double x2, double y2);
}

#endif
