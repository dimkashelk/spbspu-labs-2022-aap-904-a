#include "latin_letters.h"
#include <cctype>

char* createStringNewLatinLetters(char* destination, const char* source)
{
  size_t k = 0;
  for (char i = 'a'; i <= 'z'; i++)
  {
    for (const char* j = source; *j != '\0'; j++)
    {
      if (*j == i)
      {
        i++;
      }
      else
      {
        destination[k++] = i;
        break;
      }
    }
  }
  return destination;
}
