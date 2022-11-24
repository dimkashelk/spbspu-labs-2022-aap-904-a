#include "sequences.h"
#include <limits>
#include <stdexcept>

Localminimals::Localminimals(int min):
  count(0),
  next(min),
  current(min)
{}
unsigned int Localminimals::generalcount() const
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
    count++;
  }
  next = current;
  current = previous;
}

Minsrmax::Minsrmax(int sr):
  count(0),
  next(sr),
  current(sr)
{}
unsigned int Minsrmax::generalcount() const
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
    count++;
  }
  next = current;
  current = previous;
}
