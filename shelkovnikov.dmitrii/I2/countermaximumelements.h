#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
class CounterMaximumElements
{
public:
  CounterMaximumElements(int *arr, int count);
  unsigned int get_maximum_count();
  int get_maximum();
  ~CounterMaximumElements();
private:
  int length;
  int* arr;
};
#endif
