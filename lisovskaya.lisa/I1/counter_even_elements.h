#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTER_EVEN_ELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTER_EVEN_ELEMENTS_H
struct CounterEvenElements
{
  void operator()(int next);
  unsigned int count;
  unsigned int maxcount;
  unsigned int prev;
}
#endif

