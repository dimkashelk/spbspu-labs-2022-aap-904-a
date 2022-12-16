#ifndef CSTR_HPP
#define CSTR_HPP

#include <cstddef>
#include <iostream>

namespace odintsov {
  struct CString {
    size_t size;
    size_t cap;
    char* str;

    CString(size_t cap);
    ~CString();

    void extend(size_t newCap);
    void append(char c);
  };

  void removeLatin(const CString& cstr, CString& out);
  void removeVowels(const CString& cstr, CString& out);
}

#endif
