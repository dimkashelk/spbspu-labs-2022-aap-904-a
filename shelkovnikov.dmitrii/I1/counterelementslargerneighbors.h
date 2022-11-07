#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERLARGERNEIGHBORS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERLARGERNEIGHBORS_H
class CounterElementsLargerNeighbors
{
public:
  CounterElementsLargerNeighbors(int cur);
  void operator()(int next);
  unsigned int get_count() const;
private:
  unsigned int count;
  int previous;
  int current;
};
#endif
