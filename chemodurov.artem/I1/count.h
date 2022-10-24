#ifndef COUNT_H
#define COUNT_H
#include <iostream>

struct MinCounter
{
  void operator()(int curr_value);

  int prev_prev_value;
  int prev_value;
  unsigned int min_count;
};

struct MaxEvenCounter
{
  void operator()(int curr_value);

  unsigned int even_count;
  unsigned int max_even_count;
};
#endif
