#ifndef T1_VECTORT_H
#define T1_VECTORT_H
#include "base_types.h"
struct vector_t
{
  double x;
  double y;
  vector_t(double x, double y);
  vector_t(point_t end, point_t start);
  vector_t& operator*=(double k);
  double getLength() const;
};
#endif
