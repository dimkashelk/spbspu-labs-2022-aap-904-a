#include "isoscale.h"

void turkin::isoScale(turkin::Shape * shape, scale_t scale)
{
  turkin::point_t fst_pos = shape->getFrameRect().position;
  shape->move(scale.position);
  turkin::point_t sec_pos = shape->getFrameRect().position;
  shape->scale(scale.scale);
  double dx = (fst_pos.x - sec_pos.x) * scale.scale;
  double dy = (fst_pos.y - sec_pos.y) * scale.scale;
  shape->move(dx, dy);
}
