#include "sequences.h"

void operator()(int previous)
{
  if ((current < previous) && (current < next))
  {
    countlocalmin++;
  }
  next = current;
  current = previous;
}

void operator()(int previous)
{
  countofsequenceelements++;
  if ((countofsequenceelements >2) && (current < previous) && (current > next))
  {
    countminsrmax++;
  }
  next = current;
  current = previous;
}
