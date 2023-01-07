#include "makeNewStringWithMissingLetters.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char* makeNewStringWithMissingLetters(char* destination, const char* source)
{
  size_t new_elements = 0;
  bool match = false;
  for (char i = 'a'; i <= 'z'; i++)
  {
    match = false;
    for (size_t j = 0; source[j] != '\n'; j++)
    {
      if (std::tolower(source[j]) == std::tolower(i))
      {
        match = true;
      }
    }
    if (match == false)
    {
      destination[new_elements++] = i;
    }
  }

  destination[new_elements] = '\0';

  return destination;
}
