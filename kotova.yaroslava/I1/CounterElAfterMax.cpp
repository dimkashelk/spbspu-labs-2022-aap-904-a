#include "CounterElAfterMax.h"
#include <limits>
#include <stdexcept>

<<<<<<< HEAD
void CounterElAfterMax::operator()(int curr)
{
  const int max_int = std::numeric_limits< int >::max();
  if (curr < maxchislo)
  {
    if (count >= max_int)
    {
      throw std::overflow_error("Overflow.");
    }
    else
    {
      count++;
    }
  }
  else
  {
    maxchislo = curr;
    if (maxchislo == curr)
    {
      count = 0;
    }
  }
}
=======
void CounterElAfterMax::operator()(int curr) {
	const int max_int = std::numeric_limits< int >::max();
	if (curr < maxchislo) {
		if (count >= max_int) {
			throw std::overflow_error("Overflow.");
		}
		else {
			count++;
		}
	}
	else {
		maxchislo = curr;
		if (maxchislo == curr) {
			count = 0;
		}
	}

}
>>>>>>> kotova.yaroslava/I1
