#include <limits>
#include "count_of_maxes.h"

void count_of_maxes(const int* arr, size_t size, int& maximum, size_t& count_maximum)
{
  maximum = std::numeric_limits< int >::min();
  count_maximum = std::numeric_limits< size_t >::min();
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] > maximum)
    {
      maximum = arr[i];
      count_maximum = 1;
    }
    else
    {
      if (arr[i] == maximum)
      {
        count_maximum++;
      }
    }
  }
}
