#ifndef MINCOUNT_HPP
#define MINCOUNT_HPP

struct MinCount
{
  unsigned int minvaluecounter;
  int minvalue;

  void operator()(int value);
};
#endif
