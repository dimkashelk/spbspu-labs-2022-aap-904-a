#include <cstddef>
#include "SortIncreasing.hpp"

void sort_increasing(int* arr, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < (size - 1); j++)
    {
      if (arr[j] > arr[j + 1])
      {
        unsigned int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
