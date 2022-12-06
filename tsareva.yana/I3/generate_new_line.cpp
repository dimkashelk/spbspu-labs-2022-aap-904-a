#include "generate_new_line.h"
#include <cstddef>
char* generate_new_line(char* res, char* str1, char* str2)
{
  size_t size = 0;
  for (size_t i = 0; str1[i]; i++)
  {
    bool fl = true;
    for (size_t j = 0; str2[j]; j++)
    {
      if (str1[i] == str2[j])
      {
        fl = true;
        break;
      }
    }
    if (fl)
    {
      res[size] = str1[i];
      size++;
    }
  }
  for (size_t i = 0; str2[i]; i++)
  {
    bool fl = true;
    for (size_t j = 0; str1[j]; j++)
    {
      if (str2[i] == str1[j])
      {
        fl = true;
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
