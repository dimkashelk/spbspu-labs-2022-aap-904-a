#include "countermorethanprevious.h"
#include <limits>
#include <stdexcept>
CounterMoreThanPrevious::CounterMoreThanPrevious(int start):
  count(0),
  prev(start)
{}
void CounterMoreThanPrevious::operator()(int next)
{
  constexpr unsigned int maxint = std::numeric_limits< unsigned int >::max();
  if (next > prev)
  {
    if (count == maxint)
    {
      throw std::overflow_error("bruh...");
    }
    count++;
  }
  prev = next;
}
unsigned int CounterMoreThanPrevious::get_count() const
{
  return count;
}
