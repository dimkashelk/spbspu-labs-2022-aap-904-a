#include"countrowswithdifferentelements.h"

size_t countRowsWithDifferentElements(int* arr, const size_t m, const size_t n)
{
  size_t count = 0;
  size_t elementscounter = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        elementscounter++;
      }
    }
    if (elementscounter == 0)
    {
      count++;
    }
    elementscounter = 0;
  }
   return count;
}