#include "FindChainOfNumbers.hpp"
#include <cstddef>

int find_chain(int* arr, size_t size)
{
  unsigned int count = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] + 1 == arr[i+1])
    {
      count++;
    }
  }

  return count;
}