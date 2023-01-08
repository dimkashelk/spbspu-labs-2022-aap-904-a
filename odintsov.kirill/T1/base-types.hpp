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
  rectangle_t getFrameRectFromCorners(const point_t& bl, const point_t& tr);
  point_t getFrameRectBottomLeftCorner(const rectangle_t& rect);
  point_t getFrameRectTopRightCorner(const rectangle_t& rect);
  rectangle_t getFrameRectFromPoints(const point_t* points, size_t amt);
  bool isPointInRectangle(const point_t& p, const rectangle_t& rect);
}

#endif
