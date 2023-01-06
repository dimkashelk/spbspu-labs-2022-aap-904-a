#include "extendString.hpp"
#include <stdexcept>
#include <cstring>

char* zasulsky::extendString(const char* src, size_t cap, size_t newCap)
{
  if (newCap < cap) {
    throw std::invalid_argument("New string capacity must increase");
  }
  char* newstr = new char[newCap];
  std::strcpy(newstr, src);
  return newstr;
}
