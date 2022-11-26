#include "sequences.h"
#include <limits>
#include <stdexcept>

Localminimals::Localminimals(int prev):
  count(0),
  current(prev),
  next(prev)
{}

unsigned int Localminimals::totalcount() const
{
  return count;
}


void Localminimals::operator()(int previous)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  if ((current < previous) && (current < next))
  {
    if (count == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    else
    {
      count++;
    }
  }
  next = current;
  current = previous;
}

Minsrmax::Minsrmax(int prev):
  countofsequenceelements(0),
  count(0),
  current(prev),
  next(prev)
{}

unsigned int Minsrmax::totalcount() const
{
  return count;
}

void Minsrmax::operator()(int previous)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  countofsequenceelements++;
  if ((countofsequenceelements >2) && (current < previous) && (current > next))
  {
    if (count == max_unsigned_int)
    {
      throw std::overflow_error("Overflow...");
    }
    else
    {
      count++;
    }
  }
  next = current;
  current = previous;
}
