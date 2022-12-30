#include "sortstringbyascii.h"
#include <cctype>
#include <stdexcept>

void swapEl(size_t elstr, char* newstr3)
{
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
}
bool compare(char* i, char* q)
{
  bool match = false;
  for (char* j = i + 1; *j; j++)
  {
    if ((std::toupper(*i)) == std::toupper(*j))
    {
      match = true;
      break;
    }
  }
  for (char* z = q; *z; z++)
  {
    if ((std::toupper(*i)) == std::toupper(*z))
    {
      match = true;
      break;
    }
  }
  return match;
}
char* sortStringByAscii(char* newstr3, char* cstring, char* newstr2)
{
  size_t elstr = 0;
  char* q = newstr2;
  for (char* i = cstring; *i; i++)
  {
    if (std::isalpha(*i))
    {
      bool matching = compare(i, q);
      if (!matching)
      {
        newstr3[elstr++] = std::toupper(*i);
      }
    }
  }
  for (char* i = newstr2; *i; i++)
  {
    if (std::isalpha(*i))
    {
      bool matching = compare(i, q);
      if (matching)
      {
        newstr3[elstr++] = std::toupper(*i);
      }
    }
  }
  swapEl(elstr, newstr3);
  newstr3[elstr] = '\0';
  return newstr3;
}
