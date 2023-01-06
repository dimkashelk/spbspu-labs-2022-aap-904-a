#include "IsoScale.hpp"
#include "Shape.hpp"
#include "Base-types.hpp"

void isoScale(Shape *shape, scale_t s_value)
{
  point_t position1 = shape->getFrameRect().pos;
  shape->move(s_value.pos);
  point_t position2 = shape->getFrameRect().pos;
  shape->makeSafeScale(s_value.scale);
  double dx = (position1.x - position2.x) * s_value.scale;
  double dy = (position1.y - position2.y) * s_value.scale;
  shape->move(dx, dy);
}