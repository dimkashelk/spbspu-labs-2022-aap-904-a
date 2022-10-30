#ifndef SECONDMAX_HPP
#define SECONDMAX_HPP
struct SecondMax
{
  void operator()(int curr_value);
  int first_max = 0;
  int second_max = 0;
};
#endif
