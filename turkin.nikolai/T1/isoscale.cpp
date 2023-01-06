#include "isoscale.h"

double computeDS(double one, double two, double scale)
{
  return (two - one) * scale;
}

void turkin::isoScale(Shape * shape, scale_t scale)
{
  point_t fst_pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  point_t sec_pos = shape->getFrameRect().pos;
  shape->scaleP(scale.scale);
  double dx = computeDS(fst_pos.x, sec_pos.x, scale.scale);
  double dy = computeDS(fst_pos.y, sec_pos.y, scale.scale);
  shape->move(dx, dy);
}

