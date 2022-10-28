#include "sequence.hpp"

void odintsov::LargestCounter::operator()(int v) {
  if (v > largestVal) {
    largestVal = v;
    n = 1;
  } else if (v == largestVal) {
    n++;
  }
};

void odintsov::DescendingCounter::operator()(int v) {
  bool curValDescending = (v < lastVal);
  if (lastValDescending && curValDescending) {
    n++;
  }
  lastVal = v;
  lastValDescending = curValDescending;
};
