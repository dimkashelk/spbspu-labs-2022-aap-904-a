#include "countermaximumelements.h"
#include <limits>
#include <stdexcept>
CounterMaximumElements::CounterMaximumElements(int *arr, int count):
  length(count),
  arr(arr)
{}
unsigned int CounterMaximumElements::get_maximum_count() const
{
  int count = 0;
  const int maximum = get_maximum();
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (int i = 0; i < length; i++)
  {
    if (maximum == arr[i])
    {
      if (count + 1 == max_int)
      {
        throw std::overflow_error("Too much numbers....");
      }
      count++;
    }
  }
  return count;
}
CounterMaximumElements::~CounterMaximumElements()
{
  delete[] arr;
}
int CounterMaximumElements::get_maximum() const
{
  int maximum = arr[0];
  for (int i = 0; i < length; i++)
  {
    if (maximum < arr[i])
    {
      maximum = arr[i];
    }
  }
  return maximum;
}
