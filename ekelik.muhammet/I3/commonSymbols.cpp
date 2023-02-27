#include "commonSymbols.h"

#include <cstddef>
#include <cstring>

char* findCommonSymbols(char* myCommonSymbols, const char* source1, size_t symbols)
{
  size_t count[256] = {};
  size_t len = symbols;
  for (size_t i = 0; i < len; i++)
  {
    size_t index = source1[i];
    count[index]++;
  }
  size_t j = 0;
  for (int k = 0; k < 3; k++)
  {
    size_t maxCount = 0;
    char maxChar;
    for (int i = 0; i < 256; i++)
    {
      if (count[i] > maxCount)
      {
        maxCount = count[i];
        maxChar = i;
      }
    }
    if (maxCount == 0)
    {
      break;
    }
    myCommonSymbols[j++] = maxChar;
    count[maxChar] = 0;
  }
  myCommonSymbols[j] = '\0';
  return myCommonSymbols;
}
