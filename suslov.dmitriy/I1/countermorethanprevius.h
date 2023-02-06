#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERMORETHANPREVIOUS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERMORETHANPREVIOUS_H
class CounterMoreThanPrevious {
public:
  CounterMoreThanPrevious(int start);
  void operator()(int next);
  unsigned int get_count() const;
private:
  unsigned int count;
  int prev;
};
#endif
