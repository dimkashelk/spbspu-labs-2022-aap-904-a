#include "delete_identical_chars.h"
#include <cctype>
#include <cstddef>

char *delete_identical_chars(char *destination, const char *cstring_first, const char *cstring_second)
{
  size_t k = 0;
  size_t i = 0;
  size_t j = 0;
  bool identical_chars = false;

  while (cstring_first[i])
  {
    while (cstring_second[j])
    {
      if (cstring_first[i] == cstring_second[j])
      {
        identical_chars = true;
        break;
      }
      j++;
    }

    if (!identical_chars)
    {
      destination[k]=cstring_first[i];
      k++;
    }

    i++;
    j = 0;
    identical_chars = false;
  }

  destination[k] = '\0';
  return destination;
}
