#ifndef LENGTHEVENCOUNT_H
#define LENGTHEVENCOUNT_H

struct LenEvenCounter
{
  int count_even;
  unsigned int count_len_even;

  void operator()(int curr_val);
};

#endif
