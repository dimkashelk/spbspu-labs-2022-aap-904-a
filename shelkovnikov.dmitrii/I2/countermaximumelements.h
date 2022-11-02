#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
class CounterMaximumElements
{
public:
  CounterMaximumElements(int *arr, int count);
  unsigned int get_maximum_count() const;
  int get_maximum() const;
private:
  int length;
  int *arr;
};
#endif //SPBSPU_LABS_2022_AAP_904_A_COUNTERMAXIMUMELEMENTS_H
