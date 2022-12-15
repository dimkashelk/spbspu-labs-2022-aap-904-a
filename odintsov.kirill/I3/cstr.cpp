#include "cstr.hpp"

odintsov::CString::CString(size_t cap):
  size(0),
  cap(cap),
  str(new char[cap])
{}
