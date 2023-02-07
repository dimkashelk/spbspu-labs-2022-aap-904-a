#include "golden_ratio.h"
#include <limits>
#include <stdexcept>
#include <cmath>

size_t goldenRatio(size_t capacity)
{
  const double gRatioK = ((1 + std::sqrt(5)) / 2);
  size_t max_size_t = std::numeric_limits< size_t >::max();
  if ((max_size_t - (static_cast< int >(capacity * gRatioK) - capacity )) <= capacity )
  {
    throw std::invalid_argument("too much");
  }
  else
  {
    return capacity + (static_cast< int >(capacity * gRatioK));
  }
}
