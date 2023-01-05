#include "isoscale.h"
#include <stdexcept>

void turkin::isoScale(Shape * shape, scale_t scale)
{
  point_t fst_pos = shape->getFrameRect().position;
  shape->move(scale.position);
  point_t sec_pos = shape->getFrameRect().position;
  try
  {
    shape->scale(scale.scale);
  }
  catch (const std::logic_error & error)
  {
    throw std::logic_error(error.what());
  }
  double dx = (fst_pos.x - sec_pos.x) * scale.scale;
  double dy = (fst_pos.y - sec_pos.y) * scale.scale;
  shape->move(dx, dy);
}
