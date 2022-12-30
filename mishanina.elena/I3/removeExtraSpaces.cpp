#include "removeExtraSpaces.h"

char* removeExtraSpaces(char* destination, const char* cstring)
{
  int numberOfSymbols1 = 0;
  int numberOfSymbols2 = 0;
  int numberOfSpaces = 0;
  int numberOfDeletedSpaces = 0;

  for (size_t i = 0; i < strlen(cstring); i++)
  {
    if (cstring[i] != ' ')
    {
      numberOfSymbols1++;
    }
  }

  for (size_t i = 0, j = 0; i < strlen(cstring); i++)
  {
    if (cstring[i] != ' ')
    {
      numberOfSymbols2++;
    }
    if (numberOfSymbols2 == 0)
    {
      numberOfDeletedSpaces++;
      continue;
    }

    if (numberOfSymbols2 == numberOfSymbols1 && cstring[i] == ' ')
    {
      numberOfSpaces++;
    }

    if (i != 0 && cstring[i] == cstring[i - 1] && cstring[i] == ' ' && numberOfSymbols2 != numberOfSymbols1)
    {
      numberOfDeletedSpaces++;
      continue;
    }

    if (numberOfSymbols2 == numberOfSymbols1 && numberOfSpaces != 0)
    {
      numberOfDeletedSpaces++;
      continue;
    }
    destination[j] = cstring[i];
    j++;
  }
  destination[strlen(cstring) - numberOfDeletedSpaces] = '\0';
  return destination;
}
