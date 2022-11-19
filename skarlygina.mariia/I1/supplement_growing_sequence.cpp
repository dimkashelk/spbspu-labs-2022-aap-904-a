#include "supplement_growing_sequence.h"
#include <limits>
#include <stdexcept>

void MaxGrowingSequence::operator()(int value)
{
  const unsigned int max_unsigned_value = std::numeric_limits< unsigned int >::max();
  if (max_number_of_growing_sequence == max_unsigned_value)
  {
    throw std::overflow_error("Overflow value");
  }
  else if (value > value_before)
  {
    number_of_growing_sequence += 1;
  }
  else
  {
    max_number_of_growing_sequence = std::max(number_of_growing_sequence, max_number_of_growing_sequence);
    number_of_growing_sequence = 1;
  }
  value_before = value;
}
