#include "checkPythagoreanTriples.h"
#include <cstdlib>
#include <cstring>

bool isPythagoreanTriples(long x, long y, long z)
{
  return (x * x + y * y == z * z);
}
