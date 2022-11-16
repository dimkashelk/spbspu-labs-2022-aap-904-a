#ifndef MINCOUNT_HPP
#define MINCOUNT_HPP

struct MinCount
{
  void operator()(int value);
  int minvaluecounter = 0;
  int minvalue = 0;
};
#endif
