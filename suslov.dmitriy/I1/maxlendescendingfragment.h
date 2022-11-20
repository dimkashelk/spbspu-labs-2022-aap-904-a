#ifndef SPBSPU_LABS_2022_AAP_904_A_MAXLENDESCENDINGFRAGMENT_H
#define SPBSPU_LABS_2022_AAP_904_A_MAXLENDESCENDINGFRAGMENT_H
class MaxLenDescendingFragment
{
public:
  MaxLenDescendingFragment(int start);
  void operator()(int next);
  unsigned int get_length() const;
private:
  unsigned int max_length;
  int prev;
  unsigned int curr_length;
};
#endif
