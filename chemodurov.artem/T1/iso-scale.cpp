#include "iso-scale.hpp"

void chemodurov::isoScale(chemodurov::Shape * s, const chemodurov::point_t & pos, double k)
{
  chemodurov::point_t fst_pos = (*s).getFrameRect().pos;
  (*s).move(pos);
  chemodurov::point_t sec_pos = (*s).getFrameRect().pos;
  (*s).scale(k);
  double dx = (fst_pos.x - sec_pos.x) * k;
  double dy = (fst_pos.y - sec_pos.y) * k;
  (*s).move(dx, dy);
}
