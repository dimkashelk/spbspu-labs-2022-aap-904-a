#include "CheckRepeatingElements.h"
#include <stdexcept>

size_t checkRepeatEl(const int* array, size_t size, size_t index_m, size_t index_n)
{
  size_t repeat_cnt = 0;
  if (index_n > size)
  {
    throw std::invalid_argument("Error");
  }
  if (index_m == index_n)
  {
    repeat_cnt = 0;
  }
  for (size_t i = index_m; i <= index_n; i++)
  {
    for (size_t j = index_m; j <= index_n-1; j++)
    {
      if (array[i] == array[j] && i != j)
      {
        repeat_cnt++;
        break;
      }
    }
  }
  return repeat_cnt;
}

