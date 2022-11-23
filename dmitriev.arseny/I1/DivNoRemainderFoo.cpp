#include "DivNoRemainderFoo.h"
#include <stdexcept>
#include <limits>

void defDivNoRemainder(unsigned int& divNoRemainder, const int p1, const int  p2)
{
  if (p1 != 0 && p2 % p1 == 0)
  {
    if (divNoRemainder == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    divNoRemainder++;
  }
}
