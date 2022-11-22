#include "sequences.h"
#include <limits>
#include <stdexcept>

void operator()(int previous, std::istream& in)
{
  if (in)
  {
    if ((current < previous) && (current < next))
    {
      countlocalmin++;
    }
    next = current;
    current = previous;
  }
}

void operator()(int previous, std::istream& in)
{
  if (in)
  {
    countofsequenceelements++;
    if ((countofsequenceelements >2) && (current < previous) && (current > next))
    {
      countminsrmax++;
    }
    next = current;
    current = previous;
  }
}
