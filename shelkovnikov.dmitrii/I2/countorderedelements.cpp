#include "countorderedelements.h"
#include <limits>
#include <stdexcept>
unsigned int count_ordered_elements(int *arr, size_t size)
{
  unsigned int count = 0;
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (size_t i = 1; i < size; i++)
  {
    if (arr[i - 1] < arr[i])
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
