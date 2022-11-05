#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
class CounterMaximumElements
{
public:
  CounterMaximumElements(int *arr, int count);
  unsigned int get_maximum_count() const;
  ~CounterMaximumElements();
private:
  int length;
  int *arr;
  int get_maximum() const;
};
#endif //SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
