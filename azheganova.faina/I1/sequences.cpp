#include "sequences.h"
#include <limits>
#include <stdexcept>

void Localminimals::operator()(int previous)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if ((current < previous) && (current < next))
  {
    if (countlocalmin == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    countlocalmin++;
  }
  next = current;
  current = previous;
}

void Minsrmax::operator()(int previous)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  countofsequenceelements++;
  if ((countofsequenceelements >2) && (current < previous) && (current > next))
  {
    if (countminsrmax == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    countminsrmax++;
  }
  next = current;
  current = previous;
}
