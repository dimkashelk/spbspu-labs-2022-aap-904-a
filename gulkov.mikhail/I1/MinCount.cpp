#include "MinCount.hpp"
#include <stdexcept>
#include <limits>

void MinCount::operator()(int value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (minvalue == 0)
  {
    minvalue = value;
  }
  if (value != 0 && value < minvalue)
  {
    minvalue = value;
    minvaluecounter = 0;
  }
  if (value == minvalue)
  {
    if (minvaluecounter == max_unsigned_int)
    {
      throw std::overflow_error("Overflow!");
    }
    else
    {
      minvaluecounter++;
    }
  }
}
