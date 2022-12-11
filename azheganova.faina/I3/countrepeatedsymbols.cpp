#include "countrepeatedsymbols.h"

bool countRepeatedSymbols(const char* source, size_t capacity)
{
  int countofrepeatedsymbol = 1;
  for (char i = 'a'; i <= 'z'; i++)
  {
    size_t sizestring = 0;
    for (size_t sizestring = 0; sizestring < capacity; sizestring++)
    {
      if (i == source[sizestring])
      {
        countofrepeatedsymbol++;
      }
    }
    if (countofrepeatedsymbol > 1)
    {
      return true;
    }
    countofrepeatedsymbol = 0;
  }
  return false;
}
