#include "Partition.hpp"

int *partition(int* arr, size_t size)
{
  int temp = 0;
  int *lastpos = arr + size - 1;
  while (arr < lastpos)
  {
    if (*arr % 2 != 0)
    {
      for (int *i = lastpos; i > arr; i--)
      {
        if (*i % 2 == 0)
        {
          temp = *i;
          *i = *arr;
          *arr = temp;
          break;
        }
      }
    }
    arr++;
  }
  return lastpos;
}
