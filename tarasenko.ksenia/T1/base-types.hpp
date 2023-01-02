#ifndef BASETYPES_HPP
#define BASETYPES_HPP
namespace tarasenko
{
  struct point_t
  {
    double x_, y_;
    point_t(double x, double y);
  };

  struct rectangle_t
  {
    double width_, height_;
    point_t pos_;
    rectangle_t(point_t point_ld, point_t point_ru);
  };
}
#endif
