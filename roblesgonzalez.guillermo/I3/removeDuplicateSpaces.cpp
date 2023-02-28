#include <limits>
#include <cctype>
#include <cstring>
#include "removeDuplicateSpaces.h"
const char* removeDuplicateSpaces2(const char* source)
{
  const char* p = source;
  while (std::isspace(*p)) ++p;  // skip initial whitespace
  size_t size = 0;
  const size_t max_size = std::numeric_limits<size_t>::max();
  while (p[size] != '\0' && p[size] != '\n' && size < max_size - 1)
  {
    ++size;
  }
  char* destination = new char[size + 1];
  size_t dest_index = 0;
  while (*p != '\0')
  {
    if (std::isspace(*p))
    {
      char space_char = *p++;
      while (std::isspace(*p)) ++p;  // skip subsequent whitespace
      destination[dest_index++] = space_char;
    }
    else
    {
      destination[dest_index++] = *p++;
    }
  }
  while (dest_index > 0 && std::isspace(destination[dest_index - 1]))
  {
    --dest_index;
  }
  destination[dest_index] = '\0';
  return destination;
}
