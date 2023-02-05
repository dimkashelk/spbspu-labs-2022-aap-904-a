#include "createNewStringFromThreeOfenLetters.h"
#include <cstddef>
#include <iostream>
#include <cstddef>

char* createNewStringFromThreeOftenLetters(char* fromThreeLetters, const char* string1, size_t endIndex)
{
  int countLetter = 0;
  size_t index = 0;
  int arrCountyOfLetter[3]{};
  for (const char* i = string1; *i; i++)
  {
    bool comparison = true;
    for (const char* j = fromThreeLetters; endIndex != 3; j++, endIndex)
    {
      if (*j == *i)
      {
        comparison = false;
        break;
      }
      else
      {
        comparison = true;
      }
    }
    endIndex = 0;
    index = 0;
    if (comparison)
    {
      countLetter = 0;
      for (const char* j = string1; *j; j++)
      {
        *i == *j ? countLetter++ : countLetter;
      }
      for (char* j = fromThreeLetters; *j; j++, index++)
      {
        if (arrCountyOfLetter[index] < countLetter)
        {
          for (size_t k = 2 - index; k > index; k--)
          {
            j[k] = j[k - 1];
            arrCountyOfLetter[k] = arrCountyOfLetter[k - 1];
          }
          *j = *i;
          arrCountyOfLetter[index] = countLetter;
          break;
        }
      }
      endIndex = 0;
    }
  }
  for (char* i = fromThreeLetters; *i; i++)
  {
    char* var1 = i;
    var1++;
    for (char* j = var1; *j; j++)
    {
      if (*i > *j)
      {
        char var = *i;
        *i = *j;
        *j = var;
      }
    }
  }
  return fromThreeLetters;
}
