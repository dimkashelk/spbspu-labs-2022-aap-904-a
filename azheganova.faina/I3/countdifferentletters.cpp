#include "countdifferentletters.h"

size_t count_different_letters( char* destination, const char* source, int len)
{
  size_t di = 0;
  destination[di] = '\0';
  size_t si = 0;
  int count = 0;
  while (source[si] != '\0')
  {
    std::size_t si2 = si + 1;
    while (source[si2] != '\0')
    {
      if (source[si] == source[si2])
      {
        count++;
      }
      ++si2;
    }
    if (count == 0)
    {
      destination[di] = source[si];
      ++di;
      destination[di] = '\0';
    }
    count = 0;
    ++si;
  }
  while (destination[len] != '\0')
  {
    ++len;
  }
  return len;
}
