#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERSUMPREV_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERSUMPREV_H
class CounterSumPrev
{
public:
  CounterSumPrev(int start);
  void operator()(int next);
  unsigned int get_count() const;
private:
  int prev1;
  int prev2;
  unsigned int count;
};
#endif
