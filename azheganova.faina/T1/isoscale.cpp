#include "isoscale.h"
#include <iostream>

void checkisoScale(Shape *shape, point_t position, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  isoScale(shape, position, k);
}


void isoScale(Shape * shape, const point_t & position, double k)
{
  point_t position1 = shape->getFrameRect().pos;
  shape->move(position);
  point_t position2 = shape->getFrameRect().pos;
  shape->scale(k);
  double dx = (position1.x - position2.x) * (-k);
  double dy = (position1.y - position2.y) * (-k);
  shape->move(dx, dy);
}
