#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERORDEREDELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERORDEREDELEMENTS_H
class CounterOrderedElements
{
public:
  CounterOrderedElements(int *arr, int count);
  unsigned int get_count() const;
  ~CounterOrderedElements();
private:
  int length;
  int* arr;
};
#endif
