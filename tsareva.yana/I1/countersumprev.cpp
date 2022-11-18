#include "countersumprev.h"
#include <limits>
#include <stdexcept>
CounterSumPrev::CounterSumPrev(int start):
  prev1(start),
  prev2(start),
  count(0)
{}
void CounterSumPrev::operator()(int next)
{
  constexpr unsigned int maxUInt = std::numeric_limits< unsigned int >::max();
  constexpr int maxInt = std::numeric_limits<int>::max();
  if (maxInt - prev1 < prev2)
  {
    throw std::overflow_error("Too big numbers");
  }
  if (next == prev1 + prev2)
  {
    if (count == maxUInt)
    {
      throw std::overflow_error("Too much numbers");
    }
    count++;
  }
  prev1 = prev2;
  prev2 = next;
}
unsigned int CounterSumPrev::get_count() const
{
  return count;
}
