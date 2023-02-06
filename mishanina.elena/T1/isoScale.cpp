#include "isoScale.h"

void isoScale(Shape* shape, const point_t& pos, double k)
{
  point_t pos1 = shape->getFrameRect().pos;
  shape->move(pos);
  point_t pos2 = shape->getFrameRect().pos;
  shape->scale(k);
  double dx = (pos1.x - pos2.x) * k;
  double dy = (pos1.y - pos2.y) * k;
  shape->move(dx, dy);
}
