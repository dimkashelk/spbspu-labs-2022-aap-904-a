#include "DelNumbers.h"
#include <cctype>
#include <cstddef>
char* deleteNumbers(char* destination,const char* source)
{
  size_t k = 0;
  destination[k] = '\0';
  size_t i = 0;
  while (source[i] != '\0')
  {
    if (!std::isdigit(source[i]))
    {
      destination[k] = source[i];
      ++k;
    }
    i++;
  }
  return destination;
}
