#ifndef BASETYPES_HPP
#define BASETYPES_HPP
namespace tarasenko
{
  struct point_t
  {
    double x_, y_;
  };

  struct rectangle_t
  {
    double width_, height_;
    point_t pos_;
  };
}
#endif
