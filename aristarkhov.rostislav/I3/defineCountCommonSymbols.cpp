#include "defineCountCommonSymbols.h"

size_t defineCountCommonSymbols(const char* source, const char p)
{
  size_t count = 0;
  for (size_t i = 0; source[i] != '\0'; i++)
  {
    if (p == source[i])
    {
      count++;
    }
  }
  return count;
}
