#include "sortstringbyascii.h"
#include <cctype>
#include <stdexcept>

char* sortStringByAscii(char* newstr3, const char* cstring, const char* newstr2)
{
  size_t elstr = 0;
  for (size_t i = 0; cstring[i]; i++)
  {
    if (std::isalpha(cstring[i]))
    {
      for (size_t j = 0; newstr2[j]; j++)
      {
        if ((std::toupper(cstring[i])) == std::toupper(newstr2[j]))
        {
          newstr3[elstr++] = cstring[i];
          break;
        }
      }
    }
  }
  for (size_t i = 0; i < elstr; i++)
  {
    for (size_t j = i + 1; j < elstr; j++)
    {
      if (newstr3[i] > newstr3[j])
      {
        std::swap(newstr3[i], newstr3[j]);
      }
    }
  }
  newstr3[elstr] = '\0';
  return newstr3;
}
