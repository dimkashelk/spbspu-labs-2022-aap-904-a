#include "SumStrings.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>

void sum_strings(char *arr_sum, size_t arr_sum_len, const char *cstring_one, size_t size_one, const char *cstring_two,
                 size_t size_two)
{

  const size_t max_size_t = std::numeric_limits<size_t>::max();

  for (size_t i = 0, j = 0; i < arr_sum_len; i++)
  {
    if ((i % 2 == 0 && j < size_one - 1) || (j >= size_two - 1))
    {
      arr_sum[i] = cstring_one[j];
      if (j >= size_two - 1)
      {
        if (j == max_size_t)
        {
          throw std::overflow_error("Overflow!");
        }
        j++;
      }
    }
    else if ((i % 2 != 0 && j < size_two - 1) || (j >= size_one - 1))
    {
      arr_sum[i] = cstring_two[j];
      if (j == max_size_t)
      {
        throw std::overflow_error("Overflow!");
      }
      j++;
    }
    if (i == max_size_t)
    {
      throw std::overflow_error("Overflow!");
    }
  }

  arr_sum[arr_sum_len - 1] = '\0';

}
