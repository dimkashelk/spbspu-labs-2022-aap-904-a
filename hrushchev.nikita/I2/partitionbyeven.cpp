#include "partitionbyeven.hpp"

int* partition_by_even(int* arr, const size_t size)
{
  size_t left = 0;
  size_t right = size - 1;

  while (left < right)
  {
    while (arr[left] % 2 == 0)
    {
      left++;
      if (left == size - 1)
      {
        return arr +left;
      }
    }
    while (arr[right] % 2 != 0)
    {
      right--;
      if (right == 0)
      {
        return arr + right;
      }
    }
    if (arr[right] % 2 == 0 || arr[left] % 2 != 0)
    {
      std::swap(arr[left],arr[right]);
      left++;
      right--;
    }
    else
    {
      break;
    }
  }
  return arr + left;
}
