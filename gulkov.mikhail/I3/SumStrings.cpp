#include "SumStrings.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>
#include "ResizeCstring.hpp"

char *sum_strings(char *arr_sum, size_t size_sum, size_t capacity_sum, size_t target_length, const char *cstring_one,
                  size_t size_one, const char *cstring_two,
                  size_t size_two)
{

  const size_t max_size_t = std::numeric_limits<size_t>::max();

  for (size_t i = 0, j = 0; i < target_length; i++)
  {
    if ((i % 2 == 0 && j < size_one - 1) || (j >= size_two - 1))
    {
      arr_sum = check_and_resize(arr_sum, size_sum, capacity_sum);
      arr_sum[i] = cstring_one[j];
      size_sum++;
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
      arr_sum = check_and_resize(arr_sum, size_sum, capacity_sum);
      arr_sum[i] = cstring_two[j];
      size_sum++;
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

  return arr_sum;

}
