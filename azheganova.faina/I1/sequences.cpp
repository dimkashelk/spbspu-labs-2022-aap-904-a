#include "sequences.h"
#include <limits>
#include <stdexcept>

Localminimals::Localminimals(int number):
  count(0),
  next(number),
  current(number)
{}

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

unsigned int Localminimals::generalcount() const
{
  return count;
}

Minsrmax::Minsrmax(int number):
  count(0),
  next(number),
  current(number)
{}

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
unsigned int Minsrmax::generalcount() const
{
  return count;
}
