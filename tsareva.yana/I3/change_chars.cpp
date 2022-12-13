#include "change_chars.h"
#include <cstddef>
#include <cctype>

char* change_chars(char* res, char* str)
{
  char* i = res;
  char* j = str;
  while (*i)
  {
    *j++ = std::tolower(*i++);
  }
  *j = '\0';
  return res;
}
