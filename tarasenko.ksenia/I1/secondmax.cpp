#include "secondmax.hpp"

void SecondMax::operator()(int curr_value)
{
  if (curr_value >= first_max)
  {
   second_max = first_max;
   first_max = curr_value;
  }
  else if (curr_value > second_max)
  {
    second_max = curr_value;
  }
}
