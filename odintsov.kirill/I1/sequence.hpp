#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <iosfwd>

namespace odintsov {
  struct LargestCounter {
    void operator()(int v);
    int largestVal;
    unsigned int n;
  };
}

#endif
