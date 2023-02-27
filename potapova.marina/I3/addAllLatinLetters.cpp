#include "addAllLatinLetters.h"

void checkLatinLets(bool* const letters_existence, const char* str)
{
  for (; *str != '\0'; ++str)
  {
    if (std::isalpha(*str))
    {
      letters_existence[std::tolower(*str) - 'a'] = true;
    }
  }
}

char* addAllLatinLets(char* dest, const char* str1, const char* str2)
{
  bool lets_existence[('z' - 'a') + 1];
  for (bool& let_existence : lets_existence)
  {
    let_existence = false;
  }
  checkLatinLets(lets_existence, str1);
  checkLatinLets(lets_existence, str2);
  char* dest_end_ptr = dest;
  for (char let = 'a'; let <= 'z'; ++let)
  {
    if (lets_existence[let - 'a'])
    {
      *dest_end_ptr++ = let;
    }
  }
  *dest_end_ptr = '\0';
  return dest;
}
