#include "iscale.hpp"
#include <stdexcept>

void iScaleCheck(Shape *shape, scale_t scale)
{
  if (scale.scale <= 0)
  {
    throw std::invalid_argument("Invalid scale size");
  }
  iScaleWithoutChecking(shape, scale);
}

void iScaleWithoutChecking(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleCheck(scale.scale);
  double delta_x = findDeltaScale(pos.x, scale);
  double delta_y = findDeltaScale(pos.y, scale);
  shape->move(delta_x, delta_y);
}
