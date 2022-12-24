#ifndef T1_LINE_T_H
#define T1_LINE_T_H
#include "base_types.h"
struct line_t
{
  double A;
  double B;
  double C;
  line_t(point_t point1, point_t point2);
};
#endif
