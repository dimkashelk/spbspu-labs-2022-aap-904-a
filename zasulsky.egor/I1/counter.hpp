#ifndef COUNTER_HPP
#define COUNTER_HPP

namespace zasulsky {
  struct SecondLargestFinder {
    void operator()(int val);
    int secondLargestVal;
    int largestVal;
  };
  struct FibonacciCounter {
    void operator()(int val);
    unsigned count;
    int lastVal;
    int curVal;
  };
}

#endif
