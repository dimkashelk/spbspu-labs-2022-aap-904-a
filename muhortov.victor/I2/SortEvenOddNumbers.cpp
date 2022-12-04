#include "SortEvenOddNumbers.hpp"
#include <cstddef>

void sort_numbers(int* arr, size_t size)
{
  int* sorted_arr = new int[size];
  unsigned int travel = 0;

  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] % 2 == 0)
    {
      sorted_arr[travel] = arr[i];
      travel++;
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] % 2 != 0)
    {
      sorted_arr[travel] = arr[i];
      travel++;
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = sorted_arr[i];
  }
}
