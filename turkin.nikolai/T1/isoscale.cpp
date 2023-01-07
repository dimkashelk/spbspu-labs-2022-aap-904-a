#include "isoscale.h"

void turkin::isoScale(Shape * shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleWithVerify(scale.ds);
  shape->move((pos.x - scale.pos.x) * scale.ds, (pos.y - scale.pos.y) * scale.ds);
}

