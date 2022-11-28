#include "counters.h"
#include <limits>
#include <stdexcept>
void CounterMoreNext::operator()(int next)
{
  const unsigned int max_int = std::numeric_limits<unsigned int>::max();
  if (prev < next && prev)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Error");
    }
    count++;
  }
  prev = next;
}
void CounterDecreasing::operator()(int next)
{
  const unsigned int max_int = std::numeric_limits<unsigned int>::max();
  if (prev > next && prev)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Error");
    }
    count++;
  }
  else
  {
    if (count > max_count)
    {
      max_count = count;
    }
    count = 1;
  }
  prev = next;
}

