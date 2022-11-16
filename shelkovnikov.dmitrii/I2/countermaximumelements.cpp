#include "countermaximumelements.h"
#include <limits>
#include <stdexcept>
CounterMaximumElements::CounterMaximumElements(int *arr, int count):
  length(count),
  arr(new int[count])
{
  for (int i = 0; i < count; i++)
  {
    this->arr[i] = arr[i];
  }
}
unsigned int CounterMaximumElements::get_maximum_count()
{
  unsigned int count = 0;
  int maximum = get_maximum();
  constexpr unsigned int max_int = std::numeric_limits<unsigned int>::max();
  for (int i = 0; i < length; i++)
  {
    if (maximum == arr[i])
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
int CounterMaximumElements::get_maximum()
{
  int maximum = std::numeric_limits<int>::min();
  for (int i = 0; i < length; i++)
  {
    if (maximum < arr[i])
    {
      maximum = arr[i];
    }
  }
  return maximum;
}
CounterMaximumElements::~CounterMaximumElements()
{
  delete[] arr;
}
