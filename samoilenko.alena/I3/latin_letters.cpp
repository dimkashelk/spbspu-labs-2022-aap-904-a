#include "latin_letters.h"
#include <iostream>
#include <cstddef>

char* createStringNewLatinLetters(char* destination, const char* source)
{
  size_t ascii[26] = {0};
  size_t i = 0;
  while (source[i] != '\0')
  {
    if (isalpha(source[i]))
    {
      ascii[size_t(tolower(source[i])) - 97]++;
    }
    i++;
  }
  size_t j = 0;
  for (i = 0; i < 26; i++)
  {
    if (ascii[i] == 0)
    {
      destination[j] = char(i + 97);
      j++;
    }
  }
  destination[j] = '\0';
  return destination;
}
