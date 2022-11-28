#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERS_H
struct CounterMoreNext
{
  void operator()(int next);
  int prev;
  unsigned int count;
};
struct CounterDecreasing
{
  void operator()(int next);
  int prev;
  unsigned int count;
  unsigned int max_count;
};
#endif

