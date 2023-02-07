#include "mergingString.h"
#include <cctype>
char *mergingStr(char *destination, const char *source1, const char *source2)
{
  size_t sizein1 = 0;
  size_t sizein2 = 0;
  size_t sizeout = 0;
  while (source1[sizein1])
  {
    char sumbl = source1[sizein1];
    destination[sizeout] = sumbl;
    sizein1++;
    sizeout++;
  }
  size_t size = 0;
  char *timestr = new char[size];
  while (source2[sizein2])
  {
    char tsumbl = source2[sizein2];
    timestr[size] = tsumbl;
    size++;
    sizein2++;
  }
  for (size_t i = 0; i < size; i++)
  {
    if (std::isdigit(timestr[i]))
    {
      destination[sizeout] = timestr[i];
      sizeout++;
    }
  }
  destination[sizeout] = '\0';
  delete [] timestr;
  return destination;
}
