#include "isoscale.h"
#include <iostream>

void isoScale(shape * scale, const point_t & position, double k)
{
  point_t position1 = scale->getFrameRect().pos;
  scale->move(position);
  point_t position2= scale->getFrameRect().pos;
  scale->scale(k);
  double dx = (position1.x - position2.x) * k;
  double dy = (position1.y - position2.y) * k;
  scale->move(dx, dy);
}
