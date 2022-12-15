#include <limits>
#include <stdexcept>
#include "methods.h"

void count_of_maxes(const int* arr, size_t size, int& maximum, size_t& count_maximum)
{
  maximum = std::numeric_limits< int >::min();
  count_maximum = std::numeric_limits< size_t >::min();
  for (int i = 0; i < size; i++)
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

void shift_part_to_end(int* arr, size_t size, unsigned int start_index, unsigned int end_index)
{
  if (start_index > end_index || end_index > (size - 1))
  {
    throw std::invalid_argument("Wrong input indexes");
  }
  int shift_size = end_index - start_index;
  for (int i = 0; i < shift_size; i++)
  {
    int tmp = arr[size - i - 1];
    arr[size - i - 1] = arr[end_index - i - 1];
    arr[end_index - i - 1] = tmp;
  }
}



