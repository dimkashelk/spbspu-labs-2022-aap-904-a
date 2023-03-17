#include "removeDuplicateSpaces.h"
#include <cctype>
char *removeDuplicateSpaces2(char *destination, const char *source)
{
  size_t size = 0;
  size_t d = 0;
  while (std::isspace(source[d]))
  {
    d++;
  }
  while (source[d])
  {
    if (std::isspace(source[d]))
    {
      char space_char = source[d];
      while (std::isspace(source[d]))
      {
        d++;
      }
      destination[size] = space_char;
      size++;
      d--;
    }
    else
    {
      destination[size] = source[d];
      size++;
    }
    d++;
  }
  while (size > 0 && std::isspace(destination[size - 1]))
  {
    size--;
  }
  destination[size] = '\0';
  return destination;
}
