#include "stringTransform.h"
#include <cctype>

char * turkin::deleteNumbers(char * destination, const char * source, size_t size)
{
  size_t q = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (!std::isdigit(source[i]))
    {
      destination[q++] = source[i];
    }
  }
  destination[q] = '\0';
  return destination;
}

bool turkin::isRepeat(const turkin::CharArray & array)
{
  size_t amount = 0;
  for (size_t i = 0; i < array.size; i++)
  {
    amount = 0;
    for (size_t k = 0; k < array.size; k++)
    {
      if (array.data[i] == array.data[k])
      {
        amount++;
      }
    }
    if (amount > 1)
    {
      return true;
    }
  }
  return false;
}
