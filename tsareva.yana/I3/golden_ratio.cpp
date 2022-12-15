#include "golden_ratio.h"
#include <cstddef>
#include <cmath>

size_t goldenRatio(size_t capasity)
{
  return (capasity * ( 1 + sqrt(5))) / 2;
}
