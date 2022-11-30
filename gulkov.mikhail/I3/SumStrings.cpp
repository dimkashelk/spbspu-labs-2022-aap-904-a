#include "SumStrings.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>

void sum_strings(char *arr_sum, unsigned int arr_sum_len, const char *cstring_one, unsigned int size_one,
                 const char *cstring_two,
                 unsigned int size_two)
{

  const unsigned int max_unsigned_int = std::numeric_limits<unsigned int>::max();

  for (unsigned int i = 0, j = 0; i < arr_sum_len; i++)
  {
    if ((i % 2 == 0 && j < size_one - 1) || (j >= size_two - 1))
    {
      arr_sum[i] = cstring_one[j];
      if (j >= size_two - 1)
      {
        if (j == max_unsigned_int)
        {
          throw std::overflow_error("Overflow!");
        }
        j++;
      }
    }
    else if ((i % 2 != 0 && j < size_two - 1) || (j >= size_one - 1))
    {
      arr_sum[i] = cstring_two[j];
      if (j == max_unsigned_int)
      {
        throw std::overflow_error("Overflow!");
      }
      j++;
    }
    if (i == max_unsigned_int)
    {
      throw std::overflow_error("Overflow!");
    }
  }

  arr_sum[arr_sum_len - 1] = '\0';

}
