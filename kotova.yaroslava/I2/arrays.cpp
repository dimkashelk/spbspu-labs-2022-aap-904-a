#include <stdexcept>
#include "arrays.h"

size_t counterDivision(const int* array,const size_t size, unsigned int n)
{
  size_t cnt_div = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] % n == 0)
    {
      cnt_div++;
    }
  }
  return cnt_div;
}


size_t checkRepeatEl(const int* array, size_t size, unsigned int index_m, unsigned int index_n)
{
  size_t repeat_cnt = 1;
  size_t max_of_index = std::max(index_m, index_n);
  if (max_of_index > size)
  {
    throw std::invalid_argument("Errorrr...");
  }
  if (index_m == index_n)
  {
    repeat_cnt = 0;
  }
  for (unsigned int i = index_m; i <= index_n; i++)
  {
    for (unsigned int j = index_m; j < index_n - 1; j++)
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
