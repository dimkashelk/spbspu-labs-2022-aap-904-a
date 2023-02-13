#include "Count.h"
#include <stdexcept>
#include <limits>


void counterSignChanges(unsigned int &countSignChanges, int previous_value, int current)
{
  if ((previous_value > 0 && current < 0) || (previous_value < 0 && current > 0)) {
    if (countSignChanges == std::numeric_limits< unsigned int >::max()) {
      throw std::overflow_error("Overflow");
    }
    countSignChanges++;
  }
}

void counterMin(unsigned int &countMin, int previous, int current, int& checking)
{
  if (checking && previous < current && current != 0) {
    if (countMin == std::numeric_limits< unsigned int >::max()) {
      throw std::overflow_error("Overflow");
    }
    countMin++;
  }
  if (previous > current && previous != 0) {
    checking = 1;
  } else {
    checking = 0;
  }
}
