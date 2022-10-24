#include "counter.h"
Counter::Counter() :
  count(0),
  previous(prev),
  current(cur)
{}
Counter::Counter(int prev, int cur) :
  count(0),
  previous(prev),
  current(cur)
{}
int Counter::get_count() const
{
  return count;
}
void Counter::operator()(int next)
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
