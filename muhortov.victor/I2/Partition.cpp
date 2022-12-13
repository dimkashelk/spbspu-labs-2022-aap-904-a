#include "Partition.hpp"
#include <cstddef>

void partition(int* arr, size_t size)
{
  int num = 0;
  size_t pos = 0;
  size_t firstpos = 0;
  size_t lastpos = size - 1;
  while (firstpos < lastpos)
  {
    if (arr[firstpos] % 2 == 0)
    {
      firstpos++;
    }
    else if (firstpos < lastpos)
    {
      pos = firstpos + 1;
      while (pos <= lastpos)
      {
        if (arr[pos] % 2 != 0)
        {
          pos++;
        }
        else
        {
          num = arr[pos];
          arr[pos] = arr[firstpos];
          arr[firstpos] = num;
          firstpos++;
          break;
        }
      }
    }
    if (arr[lastpos] % 2 != 0)
    {
      lastpos--;
    }
    else if (firstpos < lastpos)
    {
      pos = lastpos - 1;
      while (pos >= firstpos)
      {
        if (arr[pos] % 2 == 0)
        {
          pos--;
        }
        else
        {
          num = arr[pos];
          arr[pos] = arr[lastpos];
          arr[lastpos] = num;
          lastpos--;
          break;
        }
      }
    }
  }
}
