#include "count.h"
#include <limits>

void MinCounter::operator()(int curr_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if (curr_value && prev_prev_value)
  {
    if (min_count == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    min_count += ((prev_prev_value > prev_value) && (prev_value < curr_value)) ? 1 : 0;
  }
  prev_prev_value = prev_value;
  prev_value = curr_value;
}

void MaxEvenCounter::operator()(int curr_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if (curr_value)
  {
    if (curr_value % 2)
    {
      even_count = 0;
    }
    else
    {
      if (even_count == max_unsigned_int)
      {
        throw std::overflow_error("Overflow...");
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

