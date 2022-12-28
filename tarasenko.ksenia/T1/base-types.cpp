#include "base-types.hpp"

point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

rectandle_t::rectangle_t(double x1, double y1, double x2, double y2):
  width_(x2 - x1),
  height_(y2 - y1),
  pos_((x1 + x2) / 2, (y1 + y2) / 2)
{}
