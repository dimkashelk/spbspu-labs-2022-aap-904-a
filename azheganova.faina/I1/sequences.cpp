#include "sequences.h"
#include <limits>
#include <stdexcept>

Localminimals::Localminimals(int previous):
  count(0)
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
    else
    {
      count++;
    }
  }
  next = current;
  current = previous;
}

Minsrmax::Minsrmax(int previous):
  count(0)
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
    else
    {
      count++;
    }
  }
  next = current;
  current = previous;
}
