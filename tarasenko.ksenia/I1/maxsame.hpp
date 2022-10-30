#ifndef MAXSAME_HPP
#define MAXSAME_HPP
struct MaxSameCounter
{
  void operator()(int curr_value);
  int prev_value = 0;
  unsigned int same_count = 1;
  unsigned int max_same_count = 0;
};
#endif
