#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTER_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTER_H
class CounterElementsLargerNeighbors
{
public:
  CounterElementsLargerNeighbors();
  CounterElementsLargerNeighbors(int prev, int cur);
  void operator()(int next);
  unsigned int get_count() const;
private:
  unsigned int count;
  int previous;
  int current;
};
#endif
