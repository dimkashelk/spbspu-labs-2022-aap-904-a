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

  for (size_t i = 0; str2[i]; i++)
  {
    bool fl = true;
    for (size_t j = 0; str1[j]; j++)
    {
      if (str2[i] == str1[j])
      {
        fl = false;
        break;
      }
    }
    if (fl)
    {
      res[size] = str2[i];
      size++;
    }
  }
  res[size] = '\0';
  return res;
}
