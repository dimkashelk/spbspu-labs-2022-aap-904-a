#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

namespace odintsov {
  void incrementSafely(unsigned int&);
  struct LargestCounter {
    void operator()(int v);
    int largestVal;
    unsigned int n;
  };
  struct DescendingCounter {
    void operator()(int v);
    int lastVal;
    bool lastValDescending;
    unsigned int n;
  };
}

#endif
