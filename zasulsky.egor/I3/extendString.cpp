#include "extendString.hpp"
#include <stdexcept>
#include <cstring>
#include <limits>

char* zasulsky::extendString(const char* src, size_t capDiff)
{
  size_t size = 1;
  for (const char* c = src; *c != '\0'; c++) {
    size++;
  }
  if (size > std::numeric_limits< size_t >::max() - capDiff) {
    throw std::overflow_error("String too large");
  }
  std::cout << size << ' ';
  char* newstr = new char[size + capDiff];
  std::strcpy(newstr, src);
  return newstr;
}
