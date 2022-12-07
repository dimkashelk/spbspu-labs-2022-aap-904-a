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

bool turkin::isRepeat(const turkin::String & string)
{
  size_t amount;
  for (size_t i = 0; i < string.size; i++)
  {
    amount = 0;
    for (size_t k = 0; k < string.size; k++)
    {
      if (string.data[i] == string.data[k])
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
