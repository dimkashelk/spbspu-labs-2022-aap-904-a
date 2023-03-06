#include "increaseCapacityMultiply2.h"
#include <cstddef>
#include <stdexcept>
#include <limits>
size_t increaseCapacityMultiply2(size_t cap)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (cap == max_size)
  {
    throw std::runtime_error("Size more than max");
  }
  return cap + cap;
}
