#include "QuantitySignChange.h"
#include <stdexcept>
#include <limits>

void QuantitySignChange::operator()(const int current_val, const int prev_val)
{
  if (prev_val != 0)
  {
    if (current_val * prev_val < 0)
    {
      if (sign_change == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Too many values");
      }
      sign_change = sign_change + 1;
    }
  }
}
