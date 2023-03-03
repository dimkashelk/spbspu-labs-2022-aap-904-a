#include "removeLatinLetters.h"
#include <cctype>
char* removeLatinLetters(char *destination, const char *source)
{
<<<<<<< HEAD
  char *src = const_cast< char* >(source);
=======
  const char *src = source;
>>>>>>> master
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
