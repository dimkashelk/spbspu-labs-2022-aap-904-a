#include "charstr.h"
#include <cctype>
#include <stdexcept>

<<<<<<< HEAD
char * chemodurov::extendCString(const char * c_str, size_t cap, size_t new_cap)
{
  if (new_cap < cap)
  {
    throw std::invalid_argument("New capacity smaller than previous");
  }
  char * new_str = new char[new_cap];
  {
    auto j = new_str;
    for (auto i = c_str; i != c_str + cap; ++i)
    {
      *j = *i;
      ++j;
    }
  }
  return new_str;
}

=======
>>>>>>> master
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
          return true;
        }
      }
    }
  }
  return false;
}

namespace chemodurov
{
  bool isVowel(char c)
  {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
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
    *j = '\0';
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
