#include "counter.hpp"
#include <stdexcept>
#include <limits>

void zasulsky::SecondLargestFinder::operator()(int val)
{
  if (val == 0) {
    if (secondLargestVal == 0) {
      throw std::logic_error("Second largest value cannot be found in input stream");
    }
    return;
  }
  if (val > largestVal) {
    const int minInt = std::numeric_limits< int >::min();
    if (largestVal != minInt) {
      secondLargestVal = largestVal;
    }
    largestVal = val;
  } else if ((val > secondLargestVal) && (val < largestVal)) {
    secondLargestVal = val;
  }
}

void zasulsky::FibonacciCounter::operator()(int val)
{
  if (val == 0) {
    if (lastVal == 0) {
      throw std::logic_error("Not enough values in input stream");
    }
    return;
  }
  if ((val == lastVal + curVal) && (lastVal != 0)) {
    const unsigned maxUnsigned = std::numeric_limits< unsigned >::max();
    if (count == maxUnsigned){
      throw std::overflow_error("Too many values in input stream");
    }
    count++;
  }
  lastVal = curVal;
  curVal = val;
}
