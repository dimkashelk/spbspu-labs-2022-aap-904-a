#include "golden_ratio.h"
#include <limits>
#include <cmath>

size_t goldenRatio(size_t capacity)
{
  size_t gRatioK = ((1 + std::sqrt(5)) / 2);
  size_t max_size_t = std::numeric_limits< size_t >::max();
  if ((max_size_t - ((gRatioK * capacity) - capacity)) > capacity)
  {
    capacity = gRatioK * capacity;
  }
  return capacity;
}
