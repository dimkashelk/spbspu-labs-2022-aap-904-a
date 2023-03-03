#include "removeDuplicateSpaces.h"
#include <cctype>
char* removeDuplicateSpaces2(char *destination, const char *source)
{
  size_t size = 0;
  size_t d = 0;
  bool last_char_was_space = false;
  while (std::isspace(source[d]))
  {
    d++;
  }
  while (source[d])
  {
    if (std::isspace(source[d]))
    {
      if (!last_char_was_space)
      {
        destination[size] = ' ';
        size++;
      }
      last_char_was_space = true;
      d++;
    }
    else
    {
      destination[size] = source[d];
      size++;
      last_char_was_space = false;
      d++;
    }
  }
  if (size > 0 && std::isspace(destination[size - 1]))
  {
    size--;
  }
  destination[size] = '\0';
  return destination;
}
