#include "makeStringExtention.h"
#include <cstddef>

char* makeStringExtention(const char* source1, size_t capacity, size_t size, size_t capacity_extention)
{
  char* new_string = new char[capacity + capacity_extention];
  char* j = new_string;
  for (const char* i = source1; i != source1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return new_string;
}
