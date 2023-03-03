#include "uncommon_symbols.h"
#include <cstring>

char* find_uncommon_symbols(char* my_symbols, const char* source1)
{
  const char* source2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
  size_t size_unique = 0;
  bool is_common = false;

  while (*source1)
  {
    is_common = false;
    for (size_t i = 0; i < std::strlen(source2); ++i)
    {
      if (*source1 == source2[i])
      {
        is_common = true;
        break;
      }
    }
    if (!is_common)
    {
      my_symbols[size_unique] = *source1;
      ++size_unique;
    }
    ++source1;
  }
  my_symbols[size_unique] = '\0';
  return my_symbols;
}
