#include "generate_new_line.h"
#include <cstddef>

char* generate_new_line(char* res, const char* str1, const char* str2)
{
  size_t size = 0;
  auto i = str1;
  auto j = str2;
  bool fl = true;
  while(*i)
  {
    fl = true;
    while (*j && fl)
    {
      if (*i == *j)
      {
        fl = false;
      }
      j++;
    }
    if (fl)
    {
      res[size] = *i;
      size++;
    }
    i++;
  }

  while(*j)
  {
    fl = true;
    while (*i && fl)
    {
      if (*j == *i)
      {
        fl = false;
      }
      i++;
    }
    if (fl)
    {
      res[size] = *j;
      size++;
    }
    j++;
  }
  res[size] = '\0';
  return res;
}
