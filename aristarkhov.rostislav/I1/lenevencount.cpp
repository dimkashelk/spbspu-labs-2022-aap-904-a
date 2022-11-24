#include "LenEvenCount.h"
#include <iostream>
#include <limits>

void  LenEvenCounter::operator()(int curr_value)
{
  if (curr_value % 2 == 0)
  {
    if (count_even == std::numeric_limits<int>::max())
    {
      throw std::overflow_error("Overflow");
    }
    else
    {
      count_even++;
      if (count_even > count_len_even)
      {
        count_len_even = count_even;
      }
    }
  }
  else
  {
    count_even = 0;
  }
}