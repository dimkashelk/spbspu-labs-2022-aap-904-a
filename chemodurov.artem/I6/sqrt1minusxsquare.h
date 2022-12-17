#ifndef SQRT1MINUSXSQUARE_H
#define SQRT1MINUSXSQUARE_H
#include <cstddef>

struct Sqrt1MinusXSquare
{
  double operator()();

  double next;
  size_t members;
  size_t max_members;
  double error;
};

#endif
