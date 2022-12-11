#include "countrepeatedsymbols.h"

bool countRepeatedSymbols(const char* source)
{
  int countofrepeatedsymbol = 1;
  for (char i = 'a'; i <= 'z'; i++)
  {
    for (size_t sizestring = 0; source[sizestring]; sizestring++)
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
