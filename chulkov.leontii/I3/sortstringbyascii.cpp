#include "sortstringbyascii.h"
#include <cctype>
#include <stdexcept>

void swapEl(size_t i, size_t elstr, char* newstr3)
{
  for (size_t j = i + 1; j < elstr; j++)
  {
    if (newstr3[i] > newstr3[j])
    {
      std::swap(newstr3[i], newstr3[j]);
    }
  }
}
char* sortStringByAscii(char* newstr3, char* cstring, char* newstr2)
{
  size_t elstr = 0;
  for (char* i = cstring; *i; i++)
  {
    bool matching = false;
    if (std::isalpha(*i))
    {
      for (char*  j = i + 1; *j; j++)
      {
        if ((std::toupper(*i)) == std::toupper(*j))
        {
          matching = true;
          break;
        }
      }
      for (char* j = newstr2 ; *j; j++)
      {
        if ((std::toupper(*i)) == std::toupper(*j))
        {
          matching = true;
          break;
        }
      }
      if (!matching)
      {
        newstr3[elstr++] = std::toupper(*i);
      }
    }
  }
  for (char* i = newstr2; *i; i++)
  {
    bool matching = false;
    if (std::isalpha(*i))
    {
      for (char* j = i + 1; *j; j++)
      {
        if ((std::toupper(*i)) == std::toupper(*j))
        {
          matching = true;
          break;
        }
      }
      if (!matching)
      {
        newstr3[elstr++] = std::toupper(*i);
      }
    }
  }
  for (size_t i = 0; i < elstr; i++)
  {
    swapEl(i, elstr, newstr3);
  }
  newstr3[elstr] = '\0';
  return newstr3;
}
