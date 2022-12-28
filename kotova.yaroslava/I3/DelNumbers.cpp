#include "DelNumbers.h"
#include <cctype>
char* deleteNumbers(char* destination, const char* source)
{
  auto k = destination;
  for (auto i = source; *i != '\0'; i++)
  {
    if (!std::isdigit(*i))
    {
      *k = *i;
      ++k;
    }
    i++;
  }
  *k = '\0';
  return destination;
}
