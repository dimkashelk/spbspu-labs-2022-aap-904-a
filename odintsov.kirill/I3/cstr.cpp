#include "cstr.hpp"
#include <cstddef>
#include <stdexcept>

odintsov::CString::CString(size_t cap):
  size(0),
  cap(cap),
  str(new char[cap])
{
  str[0] = '\0';
  size = 1;
}

odintsov::CString::~CString()
{
  delete [] str;
}

void odintsov::CString::extend(size_t newCap)
{
  if (newCap <= cap) {
    throw std::invalid_argument("Bad capacity");
  }
  char* newStr = new char[newCap];
  for (size_t i = 0; i < size; i++) {
    newStr[i] = str[i];
  }
  delete [] str;
  str = newStr;
}

void odintsov::CString::append(char c)
{
  if (size == cap) {
    extend(cap + 20);
  }
  str[size - 1] = c;
  str[size++] = '\0';
}

void odintsov::removeLatin(const CString& cstr, CString& out)
{
  for (size_t i = 0; i < cstr.size - 1; i++) {
    if (((cstr.str[i] < 'A') || (cstr.str[i] > 'Z')) && ((cstr.str[i] < 'a') || (cstr.str[i] > 'z'))) {
      out.append(cstr.str[i]);
    }
  }
}
