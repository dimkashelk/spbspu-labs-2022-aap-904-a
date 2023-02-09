#include "sort.hpp"
#include <iostream>
int sort(int arr[], int size)
{
  if (size < 0)
  {
    std::cout << "Error: size of array is wrong, try again";
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  std::cout << "Sort array: ";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
