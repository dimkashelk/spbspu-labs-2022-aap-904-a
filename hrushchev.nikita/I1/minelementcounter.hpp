#ifndef MINELEMENTCOUNTER_HPP
#define MINELEMENTCOUNTER_HPP

struct MinElementCounter
{
  void operator()(int cur_value);

  int min_value = 0;
  unsigned int count_min = 0;
};
#endif
