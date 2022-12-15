#ifndef CSTR_HPP
#define CSTR_HPP

#include <cstddef>

namespace odintsov {
  struct CString {
    size_t size;
    size_t capacity;
    char* str;
  };
}

#endif
