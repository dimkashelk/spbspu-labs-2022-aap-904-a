#include "commonSymbols.h"

#include <cstddef>
#include <cstring>

char* findCommonSymbols(char* myCommonSymbols, const char* source1, size_t symbols)
{
  size_t count[256] = {};
  size_t len = std::strlen(source1);
  for (size_t i = 0; i < len; i++)
  {
    size_t index = source1[i];
    count[index]++;
  }
  size_t j = 0;
  for (int i = 255; i >= 0; i--)
  {
    if (count[i] == 0)
    {
      continue;
    }
    char c = i;
    for (size_t k = 0; k < count[i]; k++)
    {
      myCommonSymbols[j++] = c;
      if (j == 3)
      {
        break;
      }
    }
    if (j == 3)
    {
      break;
    }
  }
  myCommonSymbols[symbols] = '\0';
  return myCommonSymbols;
}
