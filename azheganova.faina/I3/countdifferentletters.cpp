#include "countdifferentletters.h"
size_t countDifferentLetters(char* source)
{
  size_t count = 0;
  size_t lettercounter = 0;
  for (char i = 'a', j = 'A'; i <= 'z'; i++, j++)
  {
    for (size_t sizestring = 0; source[sizestring]; sizestring++)
    {
      if ((i == source[sizestring]) || (j == source[sizestring]))
      {
        lettercounter++;
      }
    }
    if (lettercounter > 0)
    {
      count++;
    }
    lettercounter = 0;
  }
  return count;
}
