#include"findstringwithconsecutiveequalelements.h"

size_t findStringWithConsecutiveEqualElements(int* arr, const size_t m, const size_t n)
{
  size_t count = 0;
  size_t maxcount = 0;
  size_t linenumber = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (arr[n] == arr[n + 1])
      {
        count++;
      }
    }
    if (count > maxcount)
    {
      maxcount = count;
      linenumber = m;
    }
  }
  return linenumber;
}
