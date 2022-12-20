#include "remove_extra_spaces.h"
#include <cctype>
#include <cstddef>

char *remove_extra_spaces(char *destination, const char *cstring)
{
  size_t k = 0;

  while (std::isspace(*cstring))
  {
    cstring++;
  }

  while (*cstring)
  {
    if (!(std::isspace(*cstring) && std::isspace(*(cstring - 1))))
    {
      destination[k] = *cstring;
      k++;
    }
    cstring++;
  }
  if (std::isspace(destination[k - 1]))
  {
    k--;
  }
  destination[k] = '\0';
  return destination;
}
