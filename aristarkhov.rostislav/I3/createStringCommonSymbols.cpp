#include "createStringCommonSymbols.h"
#include <cctype>

char* createStringCommonSymbols(char* destination2, const char* source_1, const char* source_2)
{
  size_t res = 0;
  for (size_t i = 0; source_1[i] != '\0'; i++)
  {
    if (defineCountCommonSymbols(source_1 + i + 1, source_1[i]) == 0)
    {
      if (defineCountCommonSymbols(source_2, source_1[i]) > 0)
      {
        destination2[res++] = source_1[i];
      }
    }
  }
  destination2[res] = '\0';
  return destination2;
}
