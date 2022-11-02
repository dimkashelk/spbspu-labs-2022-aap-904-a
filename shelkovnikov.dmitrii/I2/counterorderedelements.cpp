#include "counterorderedelements.h"
CounterOrderedElements::CounterOrderedElements(int *arr, int length):
  length(length),
  arr(arr)
{}
unsigned int CounterOrderedElements::get_count() const
{
  unsigned int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] < arr[i + 1])
    {
      count++;
    }
  }
  return count;
}
