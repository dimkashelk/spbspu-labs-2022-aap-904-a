#include "createNewStringFromThreeOfenLetters.h"
#include <cstddef>
#include <algorithm>

char* createNewStringFromThreeOftenLetters(char* fromThreeLetters, const char* string1, size_t endIndex)
{
  size_t countLetter = 0;
  size_t index = 0;
  size_t arrCountyOfLetter[3]{};
  for (const char* i = string1; *i; i++)
  {
    bool comparison = true;
    for (const char* j = fromThreeLetters; endIndex != 3; j++, endIndex++)
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
      for (char* j = fromThreeLetters; endIndex != 3; j++, index++, endIndex++)
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
    }
    endIndex = 0;
  }
  for (char* i = fromThreeLetters; endIndex != 3; i++, endIndex++)
  {
    char* var1 = i;
    var1++;
    size_t end = 0;
    for (char* j = var1; end != 2 - endIndex; j++, end++)
    {
      if (*i > *j)
      {
        std::swap(*j, *i)
      }
    }
  }
  return fromThreeLetters;
}
