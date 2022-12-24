#include "RepLetters.h"
#include <cctype>
#include <cstddef>

char* replacingLetters(const char* source, char* destination)
{
  size_t k = 0;
  destination[k] = '\0';
  size_t i = 0;
  while (source[i] != '\0')
  {
    if (std::isalpha(source[i]))
    {
      destination[k] = std::tolower(source[i]);
      ++k;
    }
    i++;
  }
  destination[k] = '\0';
  return destination;
}
