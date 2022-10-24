#include <iostream>
#include "counter.h"
Counter::Counter()
{}
Counter::Counter(int prev, int cur) :
  previous(prev),
  current(cur)
{}
int Counter::get_count()
{
  return count;
}
void Counter::operator()(int next)
{
  constexpr int max_int = std::numeric_limits< int >::max();
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
