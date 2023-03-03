#include "most_common_characters.h"
#include <cstddef>

bool equate(const char* source1, const char* i, size_t lastIdx)
{
  for (const char* k = source1; lastIdx != 3; lastIdx++, k++)
  {
    if (*k == *i)
    {
      return true;
    }
  }
  return false;
}

char* printMostCommonCharacters(size_t lastIdx, char* destination, const char* source)
{
  size_t arr[3]{};
  size_t idx = 0;
  size_t counter = 0;
  for (const char* i = source; *i; i++)
  {
    idx = 0;
    if (equate(destination, i, lastIdx))
    {
      counter = 0;
      for (const char* n = source; *n; n++)
      {
        if (*i == *n)
        {
          counter++;
        }
      }
      for (char* k = destination; lastIdx != 3; idx++, k++, lastIdx++)
      {
        if (arr[idx] < counter)
        {
          for (size_t m = 2 - idx; m > idx; m--)
          {
            k[m] = k[m - 1];
            arr[m] = arr[m - 1];
          }
          *k = *i;
          arr[idx] = counter;
          break;
        }
      }
    }
    lastIdx = 0;
  }
  return destination;
}