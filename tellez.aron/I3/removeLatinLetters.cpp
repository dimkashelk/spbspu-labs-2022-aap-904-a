#include <ctype.h>
#include "removeLatinLetters.h"
char* removeLatinLetters(char *destination, char *source)
{
  char *src = source;
  char *dst = destination;
  while (*src != '\0')
  {
    if (isalpha(*src))
    {
      *dst = *src;
      dst++;
    }
    src++;
  }
  *dst = '\0';
  return destination;
}
