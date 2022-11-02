#include "countermaximumelements.h"
CounterMaximumElements::CounterMaximumElements(int *arr, int count):
  length(count),
  arr(arr)
{}
unsigned int CounterMaximumElements::get_maximum_count() const
{
  int count = 0;
  const int maximum = get_maximum();
  for (int i = 0; i < length; i++)
  {
    if (maximum == arr[i])
    {
      count++;
    }
  }
  return count;
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
