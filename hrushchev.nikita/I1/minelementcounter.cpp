#include "minelementcounter.hpp"
#include <limits>
#include <stdexcept>

void MinElementCounter::operator()(int cur_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if (cur_value && min_value)
  {
    if (min_value == cur_value)
    {
      if (count_min == max_unsigned_int)
      {
        throw std::overflow_error("Overflow!");
      }
      else if (cur_value < min_value)
      {
        min_value = cur_value;
        count_min = 1;
      }
      else
      {
        count_min++;
      }
    }
  }
  else if (cur_value)
  {
    min_value = cur_value;
    count_min = 1;
  }
}

