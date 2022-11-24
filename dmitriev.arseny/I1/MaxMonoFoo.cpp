#include "MaxMonoFoo.h"
#include <stdexcept>
#include <limits>

void MaxMono::operator ()(const int p1, const int p2)
{
  if (p1 != 0 && p2 > p1)
  {
    if (k == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    k++;
    if (quantity < k)
    {
      quantity = k;
    }
  }
  else
  {
    if (quantity < k)
    {
      quantity = k;
    }
    k = 0;
  }
}
