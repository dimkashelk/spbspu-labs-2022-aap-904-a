#include "charstr.h"

char * chemodurov::extendCString(char * c_str, size_t cap, size_t new_cap)
{
  char * new_str = new char[new_cap];
  for (auto i = c_str, j = new_str; i != c_str + cap; ++i, ++j)
  {
    *j = *i;
  }
  return new_str;
}

char * chemodurov::addNumbersToFirst(const char * str_fst, const char * str_sec)
{
  size_t size_fst = 0;
  while (str_fst[size_fst] != '\0')
  {
    size_fst++;
  }
  size_fst++;
  size_t size_res = size_fst;
  size_t cap_res = size_res;
  char * str_res = new char[cap_res];
  for (size_t i = 0, j = 0; j < cap_res; ++i, ++j)
  {
    str_res[j] = str_fst[i];
  }
  for (size_t i = 0, j = 0; j < size_res; ++i, ++j)
  {
    if (str_sec[i] >= '0' && str_sec[i] <= '9')
    {
      if (size_res == cap_res)
      {
        int new_cap_res = cap_res + 20;
        char * new_res = chemodurov::extendCString(str_res, cap_res, new_cap_res);
        delete [] str_res;
        str_res = new_res;
        new_res = nullptr;
        cap_res = new_cap_res;
      }
      str_res[size_res] = '\0';
      str_res[size_res - 1] = str_sec[i];
      size_res++;
    }
  }
  return str_res;
}

bool chemodurov::isRepeatingNumbers(const char * c_str)
{
  for (auto i = c_str; *i != '\0'; ++i)
  {
    if (*i >= '0' && *i <= '9')
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

char * chemodurov::deleteVowels(const char * c_str)
{
  size_t size_str = 0;
  while (c_str[size_str] != '\0')
  {
    size_str++;
  }
  size_str++;
  char * str_res = new char[size_str];
  for (size_t i = 0, j = 0; i < size_str; ++i, ++j)
  {
    str_res[j] = c_str[i];
  }
  for (auto i = str_res; *i != '\0'; ++i)
  {
    if (*i == 'a' || *i == 'e' || *i == 'i' || *i == 'o' || *i == 'u' || *i == 'y')
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
