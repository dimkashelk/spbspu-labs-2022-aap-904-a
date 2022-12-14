#include "remove_extra_spaces.h"
#include <cctype>
#include <cstddef>

char *remove_extra_spaces(char *destination, const char *cstring)
{
  size_t n = 0;
  size_t k = 0;

  while (std::isspace(cstring[n]))
  {
    n++;
  }

  while (cstring[n])
  {
    if (!(std::isspace(cstring[n]) && cstring[n] == cstring[n - 1]))
    {
      destination[k] = cstring[n];
      k++;
    }
    n++;
  }

  if (std::isspace(destination[k - 1]))
  {
    k--;
  }

  destination[k] = '\0';
  return destination;
}
