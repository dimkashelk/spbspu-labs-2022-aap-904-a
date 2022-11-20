#include "sequences.h"
#include <limits>
#include <stdexcept>

void MaxCounter::operator()(int current_value)
{
  if (current_value > max)
  {
    max = current_value;
    count_max = 1;
  }
  else if (current_value == max)
  {
    count_max++;
  }

  if (count_max == std::numeric_limits<int>::max())
  {
    throw std::overflow_error("Overflow!");
  }
}

void MinCounter::operator()(int current_value)
{
  if (current_value < min && current_value != 0)
  {
    min = current_value;
    count_min = 1;
  }
  else if (current_value == min)
  {
    count_min++;
  }

  if (count_min == std::numeric_limits<int>::max())
  {
    throw std::overflow_error("Overflow!");
  }
}
