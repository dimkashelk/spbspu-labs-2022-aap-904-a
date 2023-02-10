#include "compareChar.h"
#include <cstddef>

bool compare(const char* string1, const char* fromThreeLetters, size_t endIndex)
{
  for (const char* j = fromThreeLetters; endIndex != 3; j++, endIndex++)
  {
    if (*j == *i)
    {
      return false;
    }
  }
  return true;
}
