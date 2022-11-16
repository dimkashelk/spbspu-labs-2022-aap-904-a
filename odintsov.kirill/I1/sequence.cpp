#include "sequence.hpp"
#include <limits>
#include <stdexcept>

void odintsov::incrementSafely(unsigned int& n) {
  const unsigned int maxUInt = std::numeric_limits< unsigned int >::max();
  if (n == maxUInt) {
    throw std::overflow_error("Error: too many values in the input stream");
  }
  n++;
}

void odintsov::LargestCounter::operator()(int v) {
  if (v > largestVal) {
    largestVal = v;
    n = 1;
  } else if (v == largestVal) {
    incrementSafely(n);
  }
};

void odintsov::DescendingCounter::operator()(int v) {
  bool curValDescending = (v < lastVal);
  if (lastValDescending && curValDescending) {
    incrementSafely(n);
  }
  lastVal = v;
  lastValDescending = curValDescending;
};
