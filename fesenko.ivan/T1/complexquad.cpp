#include "complexquad.h"
#include "suportFunctions"

Complexquad::Complexquad(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4):
  p1_(point1),
  p2_(point2),
  p3_(point3),
  p4_(point4)
{
  if (!isIntersectionOfSegments(p1_, p2_, p3_, p4_)) {
    throw std::invalid_argument("It`s not a complexquad\n");
  }
}
