#include "cstrfnc.h"
#include <cmath>
#include <stdexcept>

std::pair< char*, size_t > getCString(std::istream& stream)
{
  size_t size = 0;
  size_t capacity = 10;
  char* str = new char[capacity + 1];
  str[0] = '\0';
  stream >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      capacity = static_cast< size_t >(capacity * std::sqrt(2));
      char* newstr = new char[capacity + 1];
      str[size] = '\0';
      std::strcpy(newstr, str);
      delete[] str;
      str = newstr;
    }
    stream >> str[size++];
  }
  while (std::cin && str[size - 1] != '\n');
  str[size - 1] = '\0';
  return std::make_pair(str, size);
}

bool isIntersectedStrings(const char* str1, const char* str2)
{
  const char* s1 = str1;
  while (*s1 != '\0')
  {
    const char* s2 = str2;
    while (*s2 != '\0')
    {
      if (*s1 == *s2)
      {
        return true;
      }
      s2++;
    }
    s1++;
  }
  return false;
}

char* removeLatinVowelSymbols(char* destination, const char* source)
{
  const char vowels[] = "AaEeIiOoUu";
  size_t vowels_size = sizeof(vowels);
  char* dst = destination;
  for (auto i = source; *i != '\0'; i++)
  {
    bool found = false;
    for (size_t j = 0; j < vowels_size; j++)
    {
      if (*i == vowels[j])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      *(dst++) = *i;
    }
  }
  *dst = '\0';
  return destination;
}
