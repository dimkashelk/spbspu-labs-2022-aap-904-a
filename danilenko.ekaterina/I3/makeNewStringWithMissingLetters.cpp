#include "makeNewStringWithMissingLetters.h"
#include <cctype>
#include <cstddef>
#include <istream>
#include <stdexcept>

bool isNecessaryLetter(char* source, char letter)
{
  for (size_t i = 0; source[i] != '\0'; i++)
  {
    if (source[i] == letter)
    {
      return true;
    }
  }
  return false;
}

char* makeNewStringWithMissingLetters(char* destination, char* source)
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