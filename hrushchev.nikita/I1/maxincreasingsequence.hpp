#ifndef MAXINCREASINGSEQUENCE_HPP
#define MAXINCREASINGSEQUENCE_HPP

struct MaxIncreasingSequence
{
  int pre_value = 0;
  unsigned int cur_len_seqn = 0;
  unsigned int max_len_seqn = 0;

  void operator()(int cur_value);
};
#endif

