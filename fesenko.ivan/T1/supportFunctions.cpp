#include "supportFunctions.h"

void movePoint(point_t &p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void movePointBecauseOfScale(point_t &p, point_t &zoomCenter, double k)
{
  movePoint(p, (p.x - zoomCenter.x) * (k - 1), (p.y - zoomCenter.y) * (k - 1));
}
