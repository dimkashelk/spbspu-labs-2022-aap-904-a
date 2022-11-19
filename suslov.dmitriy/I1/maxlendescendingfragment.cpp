#include "maxlendescendingfragment.h"
#include <limits>
#include <stdexcept>
MaxLenDescendingFragment::MaxLenDescendingFragment(int start):
  max_length(0),
  prev(start),
  curr_length(0)
{}
void MaxLenDescendingFragment::operator()(int next)
{
  constexpr unsigned int maxint = std::numeric_limits<unsigned int>::max();
  if (next < prev)
  {
    if (curr_length == maxint)
    {
      throw std::overflow_error("bruh...");
    }
    curr_length++;
  }
  else
  {
    if (curr_length > max_length)
    {
      max_length = curr_length;
    }
    curr_length = 1;
  }
  prev = next;
}
unsigned int MaxLenDescendingFragment::get_length() const
{
  return max_length;
}
