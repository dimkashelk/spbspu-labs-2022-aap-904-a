#include "cstr.hpp"
#include <cstddef>
#include <stdexcept>
#include <cctype>

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
  cap = newCap;
}

void odintsov::CString::append(char c)
{
  if (size == cap) {
    extend(cap + 20);
  }
  str[size - 1] = c;
  str[size++] = '\0';
}

bool odintsov::isVowel(char c)
{
  c = static_cast< char >(std::toupper(c));
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char* odintsov::removeLatin(char* dest, const char* src)
{
  char* dptr = dest;
  for (const char* cptr = src; *cptr != '\0'; cptr++) {
    if (!std::isalpha(*cptr)) {
       *(dptr++) = *cptr;
    }
  }
  *dptr = '\0';
  return dest;
}

char* odintsov::removeVowels(char* dest, const char* src)
{
  char* dptr = dest;
  for (const char* cptr = src; *cptr != '\0'; cptr++) {
    if (!isVowel(*cptr)) {
      *(dptr++) = *cptr;
    }
  }
  *dptr = '\0';
  return dest;
}
