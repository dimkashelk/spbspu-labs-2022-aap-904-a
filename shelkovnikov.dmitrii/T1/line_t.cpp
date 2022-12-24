#include "line_t.h"
line_t::line_t(point_t point1, point_t point2):
  A(point2.y - point1.y),
  B(-(point2.x - point1.x)),
  C(-B * point1.y - A * point1.x)
{}
