#ifndef AMOUNTOFMIN_HPP
#define AMOUNTOFMIN_HPP
#include <limits>

const unsigned int MaxDlyIskl = std::numeric_limits<unsigned int>::max();


struct Znach
{
  int min;
  unsigned int counter;
  
  void operator()(int value);
};


#endif

