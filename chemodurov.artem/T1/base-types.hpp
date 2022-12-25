#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace chemodurov
{
  struct point_t
  {
    double x, y;

    point_t operator+(const point_t & right) const;
    point_t operator-(const point_t & right) const;
    point_t operator*(double k) const;
  };

  struct rectangle_t
  {
    point_t pos;
    double width, height;
  };
}

#endif
