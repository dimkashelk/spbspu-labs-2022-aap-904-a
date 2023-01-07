#include <limits>
#include "Count.h"

int CountChanges(int previous, int current) {
    if ((previous > 0 && current < 0) || (previous < 0 && current > 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

void CountMin(unsigned int &countMin, int prev, int curr, int &checking) {
  if (checking && prev < curr && curr != 0) {
    if (countMin == std::numeric_limits<unsigned int>::max())
    {
      throw std::overflow_error("Overflow");
    }
    countMin++;
  }
  if (prev > curr && prev != 0) {
    checking = 1;
  }
  else {
    checking = 0;
  }
}
