#include "findsamechar.h"

bool findSameChar(char* str, char* newstr)
{
  for (char* i = str; *i; i++)
  {
    for (char* j = newstr; *j; j++)
    {
      if (*i == *j)
      {
        return true;
      }
    }
  }
  return false;
}
