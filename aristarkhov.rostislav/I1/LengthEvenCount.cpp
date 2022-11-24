#include "LengthEvenCount.h"
#include <iostream>
#include <limits>

void LenEvenCounter::operator()(int curr_val)
{
  if (curr_val % 2 == 0)
  {
    if (count_even == std::numeric_limits< unsigned >::max())
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
