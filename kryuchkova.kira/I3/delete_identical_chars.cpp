#include "delete_identical_chars.h"
#include <cctype>
#include <cstddef>

char *delete_identical_chars(char *destination, const char *cstring_first, const char *cstring_second)
{
  bool identical_chars = false;
  size_t k = 0;
  const char *start = cstring_second;
  while (*cstring_first)
  {
    cstring_second = start;
    while (*cstring_second)
    {
      if (*cstring_first == *cstring_second)
      {
        identical_chars = true;
      }
      cstring_second++;
    }
    if (!identical_chars)
    {
      destination[k] = *cstring_first;
      k++;
    }
    identical_chars = false;
    cstring_first++;
  }
  destination[k] = '\0';
  return destination;
}
