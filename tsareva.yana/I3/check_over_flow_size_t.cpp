#include "check_over_flow_size_t.h"
#include <limits>

size_t checkOverFlowSizeT(size_t first_addend, size_t second_addend)
{
  size_t max_size_t = std::numeric_limits< size_t>::max();
  if (max_size_t - second_addend >= first_addend)
  {
    return first_addend + second_addend;
  }
}
