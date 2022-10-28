#include "sequence.hpp"
#include <iostream>
#include <limits>

void odintsov::LargestCounter::operator()(int v) {
  if (v > largestVal) {
    largestVal = v;
    n = 1;
  } else if (v == largestVal) {
    n++;
  }
};
