#include "change_register.h"
#include <cstddef>
#include <cctype>

char *change_register(char* res, const char* str)
{
  const char* i = str;
  char* j = res;
  while (*i)
  {
    *j++ = std::tolower(*i++);
  }
  *j = '\0';
  return res;
}
