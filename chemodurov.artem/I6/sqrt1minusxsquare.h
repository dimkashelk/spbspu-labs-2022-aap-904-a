#ifndef SQRT1MINUSXSQUARE_H
#define SQRT1MINUSXSQUARE_H
#include <cstddef>

struct Sqrt1MinusXSquare
{
  double operator()(size_t max_members, double error);

  double next;
  size_t members;
};

#endif
