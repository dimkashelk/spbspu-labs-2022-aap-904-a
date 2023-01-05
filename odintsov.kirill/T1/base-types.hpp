#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace odintsov {
  struct point_t {
    double x, y;
  };
  struct rectangle_t {
    double width, height;
    point_t pos;
  };
  void movePoint(point_t& p, double dx, double dy);
  void isoScalePoint(const point_t& anchor, point_t& p, double k);
}

#endif
