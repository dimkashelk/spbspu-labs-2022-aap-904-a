#include "shapesPatterns.h"

turkin::rectangle_t::rectangle_t(turkin::point_t one, turkin::point_t two):
  position{(one.x + two.y) / 2.0, (one.y + two.y) / 2.0},
  width(two.x - one.x),
  height(two.y - one.y)
{}

turkin::rectangle_t::rectangle_t(turkin::point_t one, double side):
  position{one.x + (side / 2.0), one.y + (side / 2.0)},
  width(side),
  height(side)
{}

turkin::rectangle_t::rectangle_t(turkin::point_t one, double r1, double r2):
  position{one.x, one.y},
  width(r1 * 2),
  height(r2 * 2)
{}

turkin::point_t::point_t(double nx, double ny):
  x(nx),
  y(ny)
{}

turkin::scale_t::scale_t(turkin::point_t one, double nscale):
  position(one),
  scale(nscale)
{}
