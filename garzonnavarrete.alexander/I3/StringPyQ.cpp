#include "StringPyQ.h"
#include <cstddef>

char *sum_strings(char *arr_sum, const char *cstring_p, const char *cstring_q)
{
  size_t size_sum = 0;
  for (size_t i = 0; *cstring_p || *cstring_q; i++)
  {
    if ((i % 2 == 0 && *cstring_p) || !(*cstring_q))
    {
      arr_sum[i] = *cstring_p;
      size_sum++;
      if (!(*cstring_p))
      {
        cstring_q++;
      }
      else
      {
        cstring_p++;
      }
    }
    else if ((i % 2 != 0 && *cstring_q) || !(*cstring_p))
    {
      arr_sum[i] = *cstring_q;
      size_sum++;
      cstring_q++;
    }
  }
  arr_sum[size_sum] = '\0';
  return arr_sum;
}
