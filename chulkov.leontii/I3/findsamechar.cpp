#include "findsamechar.h"

bool findSameChar(const char* str, const char* newstr)
{
  for (int i = 0; str[i]; i++)
  {
    for (int j = 0; newstr[j]; j++)
    {
      if (str[i] == newstr[j])
      {
        return true;
      }
    }
  }
  return false;
}
