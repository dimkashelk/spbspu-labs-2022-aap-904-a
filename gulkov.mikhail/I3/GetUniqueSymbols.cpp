#include "GetUniqueSymbols.hpp"
#include <cstddef>

char *get_unique_symbols(char *arr_unique, const char *cstring_one, const char *cstring_two)
{
  size_t size_unique = 0;

  bool is_common = false;

  for (; *cstring_one; cstring_one++)
  {
    for (; *cstring_two; cstring_two++)
    {
      if (*cstring_one == *cstring_two)
      {
        is_common = true;
      }
    }

    if (!is_common)
    {
      arr_unique[size_unique] = *cstring_one;
      size_unique++;
    }

    is_common = false;
  }

  arr_unique[size_unique] = '\0';

  return arr_unique;
}
