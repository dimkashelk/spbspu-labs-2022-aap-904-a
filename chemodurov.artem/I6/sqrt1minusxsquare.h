#ifndef SQRT1MINUSXSQUARE_H
#define SQRT1MINUSXSQUARE_H
#include <cstddef>

struct Sqrt1MinusXSquare
{
  double operator()(double x, size_t max_members, double error);

  double current;
  size_t members;
};

#endif
