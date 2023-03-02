#include "createStringCommonSymbols.h"
#include <cctype>

char* createStringCommonSymbols(char* destination2, const char* source_1, const char* source_2)
{
  char* res = destination2;
  for (const char* i = source_1; *i != '\0'; i++)
  {
    bool repetition = false;
    for (const char* j = destination2; *j != 0; j++)
    {
      if (*j == *i)
      {
        repetition = true;
        break;
      }
    }
    if (!repetition)
    {
      for (const char* j = source_2; *j != '\0'; j++)
      {
        if (*j == *i)
        {
          *res = *i;
          ++res;
        }
      }
    }
  }
  *res = '\0';
  return destination2;
}
