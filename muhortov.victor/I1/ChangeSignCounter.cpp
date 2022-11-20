#include "ChangeSignCounter.hpp"
#include <stdexcept>
#include <limits>
#include <math.h>

void CountSignChanges::operator()(int x, int y)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if (ChangeSignCounter == max_unsigned_int)
  {
    throw std::overflow_error("Overflow");
  }
  if (y != 0)
  {
    if (x / abs(x) != y / abs(y))
    {
      ChangeSignCounter += 1;
    }
  }
}
