
#include "uncommonSymbols.h"
#include <cstring>

char* findUncommonSymbols(char* mySymbols, const char* source1)
{
  const char* source2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
  size_t sizeUnique = 0;
  bool isCommon = false;

  while (*source1)
  {
    isCommon = false;
    for (size_t i = 0; i < std::strlen(source2); ++i)
    {
      if (*source1 == source2[i])
      {
        isCommon = true;
        break;
      }
    }
    if (!isCommon)
    {
      mySymbols[sizeUnique] = *source1;
      ++sizeUnique;
    }
    ++source1;
  }
  mySymbols[sizeUnique] = '\0';
  return mySymbols;
}
