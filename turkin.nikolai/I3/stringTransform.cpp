#include "stringTransform.h"
#include <cctype>

char * turkin::deleteNumbers(char * destination, const char * source)
{
  size_t i = 0;
  size_t q = 0;
  while (source[i] != '\0')
  {
    if (!std::isdigit(source[i]))
    {
      destination[q++] = source[i];
    }
    i++;
  }
  return destination;
}

bool turkin::isRepeat(const char * source)
{
  size_t amount = 0;
  size_t i = 0;
  size_t q = 0;
  while (source[i] != '\0')
  {
    amount = 0;
    q = 0;
    while (source [q] != '\0')
    {
      if (source[i] == source[q] && i != q)
      {
        amount++;
      }
      q++;
    }
    if (amount > 1)
    {
      return true;
    }
    i++;
  }
  return false;
}
