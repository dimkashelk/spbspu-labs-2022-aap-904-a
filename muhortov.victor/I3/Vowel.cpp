#include "Vowel.hpp"

char *vowel(char *destination, char *cstring, size_t size)
{
  char vowel_symbols[] = "AaEeIiOoUuYy";
  char symbol = ' ';
  int vowel_counter = 0;
  for (size_t i = 0; i < size; i++)
  {
    symbol = cstring[i];
    for (int j = 0; j < 12; j++)
    {
      if (symbol == vowel_symbols[j])
      {
        destination[vowel_counter] = symbol;
        vowel_counter++;
        break;
      }
    }
  }

  if (vowel_counter == 0)
  {
    destination[0] = ' ';
  }
  destination[vowel_counter + 1] = '\0';

  return destination;
}
