#include <cctype>
#include <cstring>
#include "removeDuplicateSpaces.h"
void removeDuplicateSpaces2(const char* source, char* destination)
{
  const char* p = source;
  while (std::isspace(*p)) ++p;  // skip initial whitespace
  size_t size = 0;
  while (*p != '\0')
  {
    if (std::isspace(*p))
    {
      char space_char = *p++;
      while (std::isspace(*p)) ++p;  // skip subsequent whitespace
      destination[size++] = space_char;
    }
    else
    {
      destination[size++] = *p++;
    }
  }
  while (size > 0 && std::isspace(destination[size - 1]))
  {
    --size;
  }
  destination[size] = '\0';
}
