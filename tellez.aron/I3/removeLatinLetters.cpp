#include "removeLatinLetters.h"
#include <cctype>
char* removeLatinLetters(char *destination,const char *source)
{
  char *src = const_cast< char* >(source);
  char *dst = destination;
  while (*src != '\0')
  {
    if (!std::isalpha(*src))
    {
      *dst = *src;
      dst++;
    }
    src++;
  }
  *dst = '\0';
  return destination;
}
