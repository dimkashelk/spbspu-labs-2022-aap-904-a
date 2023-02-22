#include <cctype>
#include "removeDigits.h"
size_t removeDigits(char * destination, const char * source)
{
  if (destination == nullptr || source == nullptr)
  {
    return -1;
  }
  char *result = destination;
  while (*source != '\0')
  {
    if (!std::isdigit(*source))
    {
      *destination = *source;
      destination++;
    }
    source++;
  }
  *destination = '\0';
  return (destination - result);
}
