#include "sequences.h"
#include <limits>
#include <stdexcept>

Localminimals::Localminimals()
{
}

void Localminimals::operator()(int previous)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if ((current < previous) && (current < next))
  {
    if (countlocalmin == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    else
    {
      countlocalmin++;
    }
  }
  next = current;
  current = previous;
}

Minsrmax::Minsrmax()
{
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
    else
    {
      countminsrmax++;
    }
  }
  next = current;
  current = previous;
}
