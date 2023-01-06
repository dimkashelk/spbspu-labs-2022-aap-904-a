#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <cstddef>

namespace odintsov {
  struct point_t {
    double x, y;
  };
  struct rectangle_t {
    double width, height;
    point_t pos;
  };
  void movePoint(point_t& p, double dx, double dy);
  void isoScalePoint(point_t& p, const point_t& anchor, double k);
  rectangle_t getFrameRectFromPoints(const point_t* points, size_t amt);
  bool isPointInRectangle(const point_t& p, const rectangle_t& rect);
}

#endif
