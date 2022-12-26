#include "RepeatSymbols.hpp"

char *repeatSymbols(char *destination,char *cstring, size_t size)
{
  size_t repeat_size = 0;
  size_t start_checking = 1;
  int repeat_counter = 0;
  char symbol = ' ';

  for (size_t counter = 0; counter < size; counter++)
  {
    symbol = cstring[counter];
    for (size_t i = start_checking; i < size; i++)
    {
      if (symbol == cstring[i] && cstring[i] != ' ')
      {
        repeat_counter++;
        cstring[i] = ' ';
      }
    }
    if (repeat_counter > 0)
    {
      destination[repeat_size] = symbol;
      repeat_size++;
    }
    repeat_counter = 0;
    start_checking ++;
  }

  destination[repeat_size] = '\0';

  return destination;
}
