#include "counterlocalmaximum.h"
#include <limits>
#include <stdexcept>
explicit CounterLocalMaximum::CounterLocalMaximum(int start):
  first(start),
  second(start),
  count(0)
{}
void CounterLocalMaximum::operator()(int number)
{
  constexpr unsigned int maxUInt = std::numeric_limits<unsigned int>::max();
  if (first < second && second < number)
  {
    if (count == maxUInt)
    {
      throw std::overflow_error("Too much numbers");
    }
    count++;
  }
  first = second;
  second = number;
}
unsigned int CounterLocalMaximum::get_count() const
{
  return count;
}
