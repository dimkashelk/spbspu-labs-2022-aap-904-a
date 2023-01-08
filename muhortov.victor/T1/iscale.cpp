#include "iscale.hpp"

void iScale(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleCheck(scale.scale);
  double delta_x = findDeltaScale(pos.x, scale);
  double delta_y = findDeltaScale(pos.y, scale);
  shape->move(delta_x, delta_y);
}
