#include "NewStringIndeticalCharacters.h"

char *newStringIndeticalCharacters(char *destination,  char *source1, char *source2)
{
  char *result = destination;
  destination[99] = '\0';
  for (char *i = source1; *i != '\0'; i++)
  {
    for (char *j = source2; *j != '\0'; j++)
    {
      bool exists = false;
      if (*i == *j)
      {
        for (char *k = destination; *k; k++)
        {
          if (*k == *i)
          {
            exists = true;
            break;
          }
        }
        if (!exists)
        {
          *result = *i;
          ++result;
        }
      }
    }
  }
  *result = '\0';
  return destination;
}
