#include "maxincreasingsequence.hpp"
#include <limits>
#include <stdexcept>

void MaxIncreasingSequence::operator()(int cur_value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (cur_value && pre_value)
  {
    if (cur_value > pre_value)
    {
      if (cur_len_seqn == max_unsigned_int)
      {
        throw std::overflow_error("Overflow!");
      }
      else if (cur_len_seqn == 0)
      {
        cur_len_seqn = 1;
      }
      cur_len_seqn++;
    }
    else if (cur_len_seqn > 0)
    {
      cur_len_seqn = 1;
    }
    if (cur_len_seqn > max_len_seqn)
    {
      max_len_seqn = cur_len_seqn;
    }
  }
  else if (cur_value)
  {
    pre_value = cur_value;
  }
}

