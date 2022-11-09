#include "maxsame.hpp"
#include <limits>
#include <stdexcept>

void MaxSameCounter::operator()(int curr_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits<unsigned int>::max();
  if (prev_value && curr_value)
  {
    if (max_same_count == max_unsigned_int)
    {
      throw std::overflow_error("Overflow!");
    }
    else if (curr_value != prev_value)
    {
      same_count = 1;
    }
    else
    {
      same_count += 1;
    }
    max_same_count = std::max(max_same_count, same_count);
  }
  prev_value = curr_value;
}
