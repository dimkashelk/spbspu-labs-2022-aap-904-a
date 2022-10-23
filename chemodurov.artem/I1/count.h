#ifndef COUNT_H
#define COUNT_H
#include <iostream>
#include <limits>

struct MinCounter
{
  void operator()(int curr_value, std::istream & in)
  {
    const int max_int = std::numeric_limits< int >::max();
    if (in && curr_value && prev_prev_value)
    {
      if (min_count == max_int)
      {
        throw std::overflow_error("Signed overflow");
      }
      min_count += ((prev_prev_value > prev_value) && (prev_value < curr_value)) ? 1 : 0;
    }
    prev_prev_value = prev_value;
    prev_value = curr_value;
  }

  int prev_prev_value;
  int prev_value;
  int min_count;
};

struct MaxEvenCounter
{
  void operator()(int curr_value, std::istream & in)
  {
    const int max_int = std::numeric_limits< int >::max();
    if (in && curr_value)
    {
      if (curr_value % 2)
      {
        even_count = 0;
      }
      else
      {
        if (even_count == max_int)
        {
          throw std::overflow_error("Signed overflow");
        }
        else
        {
          even_count++;
          if (even_count > max_even_count)
          {
            max_even_count = even_count;
          }
        }
      }
    }
  }

  int even_count;
  int max_even_count;
};
#endif
