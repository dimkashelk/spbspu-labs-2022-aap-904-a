#ifndef AMOUNTOFMIN_HPP
#define AMOUNTOFMIN_HPP
#include <limits>


struct MinValue
{
  int min;
  unsigned int counter;

  void operator()(int value);
};


#endif

