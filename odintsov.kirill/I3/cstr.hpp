#ifndef CSTR_HPP
#define CSTR_HPP

#include <cstddef>

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

  bool isVowel(char c);
  char* removeLatin(char* dest, const char* src);
  char* removeVowels(char* dest, const char* src);
}

#endif
