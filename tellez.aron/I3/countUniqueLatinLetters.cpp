#include "countUniqueLatinLetters.h"
#include <ctype.h>
#include <stdio.h>
size_t latin_alphabet[26] = {0};
size_t countLatinLetters()
{
  size_t sum = 0;
  for(size_t i = 0; i < 26; i ++)
  {
    if(latin_alphabet[i] == 1)
    {
      sum++;
    }
  }
  return sum;
}
size_t countUniqueLatinLetters(const char *source)
{
  while(*source != '\0')
  {
    if(isalpha(*source))
    {
      latin_alphabet[toupper(*source) - 65] = 1;
    }
    source++;
  }
  return countLatinLetters();
}
