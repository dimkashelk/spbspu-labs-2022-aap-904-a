#include "partitionbyeven.hpp"

int* partition_by_even(int* arr, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size - 1; j++)
    {
      if ((arr[j] % 2 == 1) && (arr[j + 1] % 2 == 0))
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] % 2 == 1)
    {
      return arr + i;
    }
  }
  return arr + size - 1;
}
