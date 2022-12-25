#include "partitionbyeven.hpp"
<<<<<<< HEAD

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
=======
#include <utility>

int* partition_by_even(int* arr, const size_t size)
{
  int* left = arr;
  int* right = arr + size - 1;

  while (left < right)
  {
    while (*left % 2 == 0)
    {
      left++;
      if (left == arr + size - 1)
      {
        return left;
      }
    }
    while (*right % 2 != 0)
    {
      right--;
      if (right == arr)
      {
        return right;
      }
    }
    if ((*right % 2 == 0) || (*left % 2 != 0))
    {
      std::swap(arr[left - arr], arr[right - arr]);
      left++;
      right--;
    }
    else
    {
      break;
    }
  }
  return left;
>>>>>>> master
}
