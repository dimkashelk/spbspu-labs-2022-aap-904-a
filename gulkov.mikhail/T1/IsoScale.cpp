#include "IsoScale.hpp"

void doIsoScale(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->makeSafeScale(scale.scale);
  point_t offset = scaleDelta(pos, scale);
  shape->move(offset.x, offset.y);
}
