#include "sortbyeven.hpp"

void sort_by_even(int* arr, const size_t size)
{
  int temp = 0;

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size - 1; j++)
    {
      if ((arr[j] % 2 == 1) && (arr[j + 1] % 2 == 0))
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
