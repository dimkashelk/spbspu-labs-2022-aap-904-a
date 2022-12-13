#include "counter_before_min.h"
#include <stdexcept>
size_t counter_before_min(const int *ar, size_t m)
{
  if (m == 0)
  {
    throw std::runtime_error("meeeeeh");
  }
  int minimum = ar[0];
  size_t count_plus = 0;
  size_t count_plus_before_min = 0;
  for (size_t i = 0; i < m; i++)
  {
    if (minimum > ar[i])
    {
      count_plus_before_min = count_plus;
      minimum = ar[i];
    }
    if (ar[i] > 0)
    {
      count_plus++;
    }
  }
  return count_plus_before_min;
}
