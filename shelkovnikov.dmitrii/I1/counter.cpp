#include "counter.h"
#include <stdexcept>
#include <limits>
CounterElementsLargerNeighbors::CounterElementsLargerNeighbors():
  count(0),
  previous(0),
  current(0)
{}
CounterElementsLargerNeighbors::CounterElementsLargerNeighbors(int prev, int cur):
  count(0),
  previous(prev),
  current(cur)
{}
unsigned int CounterElementsLargerNeighbors::get_count() const
{
  return count;
}
void CounterElementsLargerNeighbors::operator()(int next)
{
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  if (previous < current && current < next)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Too much numbers....");
    }
    else
    {
      count++;
    }
  }
  previous = current;
  current = next;
}
