#include "isoscale.h"

void chemodurov::isoScale(turkin::Shape * s, const turkin::point_t & pos, double k)
{
  turkin::point_t fst_pos = s->getFrameRect().position;
  s->move(pos);
  turkin::point_t sec_pos = s->getFrameRect().position;
  s->scale(k);
  double dx = (fst_pos.x - sec_pos.x) * k;
  double dy = (fst_pos.y - sec_pos.y) * k;
  s->move(dx, dy);
}
