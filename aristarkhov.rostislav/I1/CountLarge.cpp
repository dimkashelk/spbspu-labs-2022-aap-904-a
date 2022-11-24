#include "CountLarge.h"
#include <iostream>
#include <limits>

void CountLarg::operator()(int curr_val)
{
  if (curr_val > larg_val)
  {
    larg_val = curr_val;
    count_amount = 1;
  }
  else if (curr_val == larg_val)
  {
  count_amount++;
  }
  if (count_amount == std::numeric_limits< int >::max())
  {
    throw std::overflow_error("Overflow");
  }
}
