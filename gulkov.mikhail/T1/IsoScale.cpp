#include "IsoScale.hpp"

void doIsoScale(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->makeSafeScale(scale.scale);
  double delta_x = (pos.x - scale.pos.x) * scale.scale;
  double delta_y = (pos.y - scale.pos.y) * scale.scale;
  shape->move(delta_x, delta_y);
}
