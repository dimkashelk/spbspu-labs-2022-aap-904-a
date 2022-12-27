#include "Vowel.hpp"

char *findVowel(char *destination, const char *cstring)
{
  char latin_vowel_symbols[] = "AaEeIiOoUuYy";
  char symbol = ' ';
  int vowel_counter = 0;
  for (const char *i = cstring; *i != '\0'; i++)
  {
    symbol = *i;
    for (int j = 0; j < 12; j++)
    {
      if (symbol == latin_vowel_symbols[j])
      {
        destination[vowel_counter] = symbol;
        vowel_counter++;
        break;
      }
    }
  }

  destination[vowel_counter] = '\0';

  return destination;
}
