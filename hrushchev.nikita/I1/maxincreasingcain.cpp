#include "maxincreasingcain.hpp"
#include <limits>
#include <stdexcept>

void MaxIncreasingCain::operator()(int cur_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (cur_value && pre_value)
  {
    if (cur_len_cain == max_unsigned_int)
    {
      throw std::overflow_error("Overflow!");
    }
    else if (cur_value > pre_value)
    {
      if (cur_len_cain == 0)
      {
        cur_len_cain = 1;
      }
      cur_len_cain++;
    }
    else if (cur_len_cain > 0)
    {
      cur_len_cain = 1;
    }

    if (cur_len_cain > max_len_cain)
    {
      max_len_cain = cur_len_cain;
    }

  }
  else if (cur_value)
  {
    pre_value = cur_value;
  }
}
