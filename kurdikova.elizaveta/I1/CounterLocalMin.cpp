#include "CounterLocalMin.h"
#include <iostream>
#include <limits>

void counterMin (int &countMin, int prev, int curr, int &checking) {
  if (checking && prev < curr && curr != 0) {
    if (countMin == std::numeric_limits<int>::max())
    {
      throw std::overflow_error("Overflow");
    }
    countMin ++;
  }
  if (prev > curr && prev != 0) {
    checking = 1;
  } else {
    checking = 0;
  }
}
