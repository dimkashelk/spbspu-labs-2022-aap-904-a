#include "makeNewStringWithoutRepeat.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char* makeNewStringWithoutRepeat(char *destination, const char *source1, const char *source2)
{
  size_t new_elements = 0;
  const char* i = source1;
  while (*i != '\0')
  {
    const char* j = source2;
    while (*j != '\0' && *j != *i)
    {
      j++;
    }
    if (*j != *i)
    {
      destination[new_elements++] = *i;
    }
    i++;
  }
  destination[new_elements] = '\0';
  return destination;
}
