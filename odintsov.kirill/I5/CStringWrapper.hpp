#ifndef CSTRINGWRAPPER_HPP
#define CSTRINGWRAPPER_HPP

#include <cstddef>
#include <iostream>

namespace odintsov {
  struct CStringWrapper {
    size_t arrSize;
    size_t arrCap;
    char* str;

    explicit CStringWrapper(size_t arrCap);
    ~CStringWrapper();

    void extend(size_t newCap);
    void append(char c);
  };
}

#endif
