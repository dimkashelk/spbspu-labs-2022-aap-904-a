#include "base-types.hpp"

void odintsov::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void odintsov::isoScalePoint(const point_t& anchor, point_t& p, double k)
{
  movePoint(p, (p.x - anchor.x) * (k - 1.0), (p.y - anchor.y) * (k - 1.0));
}
