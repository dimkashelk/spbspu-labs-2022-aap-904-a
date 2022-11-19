#include "MaxSeqLen.hpp"
#include <stdexcept>
#include <limits>

void MaxSeqLen::operator()(int value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (upseqcounter == max_unsigned_int)
  {
    throw std::overflow_error("Overflow!");
  }
  if (value != 0 && value > prevalue)
  {
    upseqcounter++;
  }
  else if (value != 0 && value < prevalue)
  {
    upseqcounter = 1;
  }

  maxupseqcount = std::max(upseqcounter, maxupseqcount);
  prevalue = value;
}
