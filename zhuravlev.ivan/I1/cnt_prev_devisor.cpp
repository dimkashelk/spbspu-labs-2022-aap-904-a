#include "cnt_prev_devisor.h"
#include <limits>
#include <stdexcept>

void CntDevPrev::operator()(int value)
{
  const unsigned int maximum_of_unsigned_int = std::numeric_limits< unsigned int >::max();
  devisor_func_previous_value = devisor_func_value;
  devisor_func_value = value;
  if (devisor_func_previous_value && devisor_func_value)
  {
    cnt_devisor_counter += ((devisor_func_value % devisor_func_previous_value == 0) ? 1 : 0);
  }

  if (cnt_devisor_counter > maximum_of_unsigned_int - 1)
  {
    throw std::overflow_error("Not good");
  }
}
