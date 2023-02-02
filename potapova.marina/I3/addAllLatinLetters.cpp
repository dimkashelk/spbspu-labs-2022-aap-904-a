#include "addAllLatinLetters.h"
#include <cctype>
#include <iostream>

void addLatinLettersFromStr(char*& dest_end_ptr, const char* str)
{
  for (; *str != '\0'; ++str)
  {
    if (std::isalpha(*str))
    {
      *dest_end_ptr++ = *str;
    }
  }
}
char* addAllLatinLetters(char* dest, const char* str1, const char* str2)
{
  char* dest_end_ptr = dest;
  addLatinLettersFromStr(dest_end_ptr, str1);
  addLatinLettersFromStr(dest_end_ptr, str2);
  *dest_end_ptr = '\0';
  return dest;
}
