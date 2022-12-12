#include "SumStrings.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>
#include "ResizeCstring.hpp"

char *sum_strings(char *arr_sum, const char *cstring_one, const char *cstring_two)
{

  size_t size_sum = 0;
  const size_t max_size_t = std::numeric_limits< size_t >::max();
  bool cstring_one_ended = false;
  bool cstring_two_ended = false;

  for (size_t i = 0, j = 0; cstring_one[j] != '\0' || cstring_two[j] != '\0'; i++)
  {

    if (cstring_one[j] == '\0' && !cstring_one_ended)
    {
      cstring_one_ended = true;
    }
    if (cstring_one[j] == '\0' && !cstring_two_ended)
    {
      cstring_two_ended = true;
    }

    if ((i % 2 == 0 && !cstring_one_ended) || cstring_two_ended)
    {
      arr_sum[i] = cstring_one[j];
      if (size_sum == max_size_t)
      {
        throw std::overflow_error("Overflow!");
      }
      size_sum++;
      if (cstring_two_ended)
      {
        if (j == max_size_t)
        {
          throw std::overflow_error("Overflow!");
        }
        j++;
      }
    }
    else if ((i % 2 != 0 && !cstring_two_ended) || cstring_one_ended)
    {
      arr_sum[i] = cstring_two[j];
      if (size_sum == max_size_t)
      {
        throw std::overflow_error("Overflow!");
      }
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

  arr_sum[size_sum] = '\0';

  return arr_sum;

}
