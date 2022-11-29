#include "removeextraspaces.h"
#include <cctype>
char *remove_extra_spaces(char *destination, const char *source)
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
      while (std::isspace(source[d]))
      {
        d++;
      }
      destination[size] = ' ';
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
  while (std::isspace(destination[size - 1]))
  {
    size--;
  }
  destination[size] = '\0';
  return destination;
}
