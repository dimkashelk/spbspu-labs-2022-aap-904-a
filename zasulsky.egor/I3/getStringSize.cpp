#include "getStringSize.hpp"
#include <cstddef>

size_t zasulsky::getStringSize(const char* cstr)
{
  size_t size = 0;
  for (const char* c = cstr; *c != '\0'; c++)
  {
    size++;
  }
  return size;
}
