#include "charstr.h"
#include <cctype>
#include <stdexcept>

char * chemodurov::extendCString(char * c_str, size_t cap, size_t new_cap)
{
  if (new_cap < cap)
  {
    throw std::invalid_argument("New capacity smaller than previous");
  }
  char * new_str = new char[new_cap];
  for (auto i = c_str, j = new_str; i != c_str + cap; ++i, ++j)
  {
    *j = *i;
  }
  return new_str;
}

char * chemodurov::addNumbersToFirst(char * str_res, const char * str_fst, const char * str_sec)
{
  auto j = str_res;
  for (auto i = str_fst; *i != '\0'; ++i)
  {
    *j = *i;
    ++j;
  }
  for (auto i = str_sec; *i != '\0'; ++i)
  {
    if (std::isdigit(*i))
    {
      *(j + 1) = '\0';
      *j = *i;
      ++j;
    }
  }
  return str_res;
}

bool chemodurov::isRepeatingNumbers(const char * c_str)
{
  for (auto i = c_str; *i != '\0'; ++i)
  {
    if (std::isdigit(*i))
    {
      for (auto j = i + 1; *j != '\0'; ++j)
      {
        if (*i == *j)
        {
          return 1;
        }
      }
    }
  }
  return 0;
}

namespace chemodurov
{
  bool isVowel(char c)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    {
      return 1;
    }
    return 0;
  }
}

char * chemodurov::deleteVowels(char * str_res, const char * c_str)
{
  {
    auto j = str_res;
    for (auto i = c_str; *i != '\0'; ++i)
    {
      *j = *i;
      ++j;
    }
  }
  for (auto i = str_res; *i != '\0'; ++i)
  {
    if (chemodurov::isVowel(*i))
    {
      for (auto j = i; *j != '\0'; ++j)
      {
        *j = *(j + 1);
      }
      i--;
    }
  }
  return str_res;
}
