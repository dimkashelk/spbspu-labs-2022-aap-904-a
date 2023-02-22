#include "makeNewStringWithMissingLetters.h"
#include <cstddef>

bool isNecessaryLetter(const char* source, char letter)
{
  for (const char* i = source; *i != '\0'; i++)
  {
    if (*i == letter)
    {
      return true;
    }
  }
  return false;
}

char* makeNewStringWithMissingLetters(char* destination, const char* source)
{
  size_t new_element = 0;
  for (char i = 'a'; i <= 'z'; i++)
  {
    if (!isNecessaryLetter(source, i))
    {
      destination[new_element++] = i;
    }
  }
  destination[new_element] = '\0';
  return destination;
}
