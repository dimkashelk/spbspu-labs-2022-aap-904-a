#ifndef MAXINCREASINGSEQUENCE_HPP
#define MAXINCREASINGSEQUENCE_HPP

struct MaxIncreasingSequence
{
  void operator()(int cur_value);

  int pre_value = 0;
  unsigned int cur_len_cain = 0;
  unsigned int max_len_cain = 0;
};
#endif

