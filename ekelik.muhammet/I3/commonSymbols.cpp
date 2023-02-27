#include "commonSymbols.h"

#include <cstddef>
#include <cstring>

char* findCommonSymbols(char* myCommonSymbols, const char* source1, size_t symbols)
{
  int count[256] = {};
  size_t len = symbols;
  for (size_t i = 0; i < len; i++)
  {
    int index = source1[i];
    count[index]++;
  }
  size_t j = 0;
  for (size_t k = 0; k < 3; k++)
  {
    int maxCount = 0;
    size_t maxChar;
    for (size_t i = 0; i < 256; i++)
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
