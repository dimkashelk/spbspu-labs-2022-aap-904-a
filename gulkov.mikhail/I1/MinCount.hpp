#ifndef MINCOUNT_HPP
#define MINCOUNT_HPP

struct MinCount
{
  void operator()(int value);

  unsigned int minvaluecounter;
  int minvalue;
};
#endif

