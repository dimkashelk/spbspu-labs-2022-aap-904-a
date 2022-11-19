#ifndef MINELEMENTCOUNTER_HPP
#define MINELEMENTCOUNTER_HPP

struct MinElementCounter
{
  void operator()(int cur_value);
  unsigned int count_min = 0;
  int min_value = 0;
};
#endif

