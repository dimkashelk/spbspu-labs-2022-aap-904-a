#include "sortstringbyascii.h"
#include <cctype>
#include <stdexcept>

char* sortStringByAscii(char* newstr3, const char* cstring, const char* newstr2)
{
  size_t elstr = 0;
  for (size_t i = 0; cstring[i]; i++)
  {
    bool matching = false;
    if (std::isalpha(cstring[i]))
    {
      for (size_t j = i + 1; cstring[j]; j++)
      {
        if ((std::toupper(cstring[i])) == std::toupper(cstring[j]))
        {
          matching = true;
          break;
        }
      }
      for (size_t j = 0; newstr2[j]; j++)
      {
        if ((std::toupper(cstring[i])) == std::toupper(newstr2[j]))
        {
          matching = true;
          break;
        }
      }
      if (!matching)
      {
        newstr3[elstr++] = std::toupper(cstring[i]);
      }
    }
  }
  for (size_t i = 0; newstr2[i]; i++)
  {
    bool matching = false;
    if (std::isalpha(newstr2[i]))
    {
      for (size_t j = i + 1; newstr2[j]; j++)
      {
        if ((std::toupper(newstr2[i])) == std::toupper(newstr2[j]))
        {
          matching = true;
          break;
        }
      }
      if (!matching)
      {
        newstr3[elstr++] = std::toupper(newstr2[i]);
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
