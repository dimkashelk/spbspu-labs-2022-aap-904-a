#include "counteraftermaximum.h"
#include <stdexcept>
#include <limits>
CounterAfterMaximum::CounterAfterMaximum(int number):
  count(0),
  maximum(number)
{}
unsigned int CounterAfterMaximum::get_count() const
{
  return count;
}
void CounterAfterMaximum::operator()(int next)
{
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  if (next < maximum)
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
  else
  {
    maximum = next;
    count = 0;
  }
}
