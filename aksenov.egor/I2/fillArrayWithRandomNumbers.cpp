#include "fillArrayWithRandomNumbers.h"
#include <cstdlib>
#include <ctime>
int *fillArrayWithRandomNumbers(size_t size)
{
  int *arr = new int[size];
  std::srand(std::time(nullptr));
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = std::rand();
  }
  return arr;
}
