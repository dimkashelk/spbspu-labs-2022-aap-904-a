#include "order.h"
#include <algorithm>
int *partition(int *arr, size_t size)
{
  if (size == 0 )
  {
    return 0;
  }
  int *l = arr;
  int *r = arr + size - 1;
  if (l == r)
  {
    return l;
  }
  if (l < r)
  {
    do
    {
      while (*l % 2 == 0)
      {
        l++;
        if (l == arr + size - 1)
        {
          return l;
        }
      }
      while (*r % 2 != 0)
      {
        r--;
        if (r == arr)
        {
          return r;
        }
      }
      if ((*l % 2 != 0) || (*r % 2 == 0))
      {
        std::swap(arr[l - arr], arr[r - arr]);
        l++;
        r--;
      }
    }
    while (l < r);
  }
  else
  {
    return 0;
  }
  return l;
}
