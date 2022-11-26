#ifndef AMOUNTOFAVR_HPP
#define AMOUNTIFAVR_HPP
#include <limits>

const unsigned int MaxDlyIskl2 = std::numeric_limits< unsigned int >::max();

struct Family
{
  int dite = 0;
  int papa = 0;
  int ded = 0;
  unsigned int counter1 = 0;

  void operator()(int value);
};

#endif
