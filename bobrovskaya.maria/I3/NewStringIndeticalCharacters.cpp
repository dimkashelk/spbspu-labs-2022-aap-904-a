#include "NewStringIndeticalCharacters.h"

char* newStringIndeticalCharacters(char* destination, const char* source1, const char* source2)
{
  char* result = destination;
  for (const char* i = source1; *i != '\0'; i++)
  {
    for (const char* j = source2; *j != '\0'; j++)
    {
      if (*i == *j)
      {
        *result = *i;
        ++result;
      }
    }
  }
  *result = '\0';
  return destination;
}
