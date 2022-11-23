#include "MaxMonoFoo.hpp"
#include <stdexcept>
#include <limits>

void defMaxMono(unsigned int& maxMono, unsigned int& k, const int p1, const int p2)
{
  if (p1 != 0 && p2 > p1)
  {

    if (k == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    k++;
    if (maxMono < k)
    {
      maxMono = k;
    }
  }
  else
  {
    if (maxMono < k)
    {
      maxMono = k;
    }
    k = 0;
  }
}
