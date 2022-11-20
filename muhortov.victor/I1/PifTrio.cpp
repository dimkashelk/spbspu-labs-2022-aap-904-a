#include "PifTrio.hpp"
#include <stdexcept>
#include <limits>

void FindPifTrio::operator()(int x, int y, int z)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (PifCounter == max_unsigned_int)
  {
    throw std::overflow_error("Overflow");
  }
  if (x > 0 && y > 0 && z > 0 && z * z + y * y == x * x)
  {
    PifCounter += 1;
  }
}
