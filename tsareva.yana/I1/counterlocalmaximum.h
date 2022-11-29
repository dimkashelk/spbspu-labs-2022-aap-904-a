#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERLOCALMAXIMUM_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERLOCALMAXIMUM_H
class CounterLocalMaximum
{
public:
  explicit CounterLocalMaximum(int start);
  void operator()(int number);
  unsigned int get_count() const;
private:
  int first;
  int second;
  unsigned int count;
};
#endif
