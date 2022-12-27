#include "RepeatSymbols.hpp"

char *repeatSymbols(char *destination, char *cstring)
{
  int repeat_counter = 0;
  char symbol = ' ';

  while (*cstring)
  {
    symbol = *cstring;
    for (char *i = cstring + 1; *i != '\0'; i++)
    {
      if (symbol == *i)
      {
        repeat_counter++;
        *i = ' ';
      }
    }
    if (repeat_counter > 0 && symbol != ' ')
    {
      *destination = symbol;
      destination++;
    }
    repeat_counter = 0;
    cstring++;
  }

  *destination = '\0';

  return destination;
}
