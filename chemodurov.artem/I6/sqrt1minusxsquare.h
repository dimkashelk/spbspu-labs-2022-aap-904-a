#ifndef SQRT1MINUSXSQUARE_H
#define SQRT1MINUSXSQUARE_H
#include <cstddef>

struct sqrt1minusxsquare
{
  double operator()(double error);

  double next;
  size_t members;
};

#endif
