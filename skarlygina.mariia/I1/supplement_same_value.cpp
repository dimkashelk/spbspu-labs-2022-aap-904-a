#include "supplement_same_value.h"
#include <limits>
#include <stdexcept>

void MaxSameValue::operator()(int value)
{
  const unsigned int max_unsigned_value = std::numeric_limits<unsigned int>::max();
  if(max_number_of_same_value == max_unsigned_value)
  {
    throw std::overflow_error("Overflow value");
  }
  else if (value == value_before)
  {
    number_of_same_value += 1;
  }
  else
  {
    max_number_of_same_value = std::max(number_of_same_value, max_number_of_same_value);
    number_of_same_value = 1;
  }
  value_before = value;
}
