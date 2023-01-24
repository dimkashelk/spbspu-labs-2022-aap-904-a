#include "generate_new_line.h"
#include <cstddef>

void generate_new_line(char* res, const char* str1, const char* str2)
{
  auto i = str1;
  auto j = str2;
  bool noMatches = true;
  while(*i)
  {
    noMatches = true;
    while (*j && noMatches)
    {
      if (*i == *j)
      {
        noMatches = false;
      }
      j++;
    }
    if (noMatches)
    {
      *res++ = *i;
    }
    i++;
  }

  while(*j)
  {
    noMatches = true;
    while (*i && noMatches)
    {
      if (*j == *i)
      {
        noMatches = false;
      }
      i++;
    }
    if (noMatches)
    {
      *res++ = *i;
    }
    j++;
  }
  *res = '\0';
}
