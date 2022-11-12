#include "counterorderedelements.h"
#include <limits>
#include <stdexcept>
CounterOrderedElements::CounterOrderedElements(int *arr, int length):
  length(length),
  arr(arr)
{}
unsigned int CounterOrderedElements::get_count() const
{
  unsigned int count = 0;
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (int i = 0; i < length - 1; i++)
  {
    if (arr[i] < arr[i + 1])
    {
      if (count == max_int)
      {
        throw std::overflow_error("Too much numbers....");
      }
      count++;
    }
  }
  return count;
}
CounterOrderedElements::~CounterOrderedElements()
{
  delete[] arr;
}
