#include "increaseCapacityAdd20.h"
#include <cstddef>
#include <limits>
#include <stdexcept>
size_t increaseCapacityAdd20(size_t cap)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (cap == max_size)
  {
    throw std::overflow_error("Size more than max");
  }
  else
  {
    return cap + 20;
  }
}
