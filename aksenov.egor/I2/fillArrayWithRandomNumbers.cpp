#include "fillArrayWithRandomNumbers.h"
#include <cstdlib>
#include <ctime>
int *fillArrayWithRandomNumbers(size_t size)
{
  int *dynamic_arr = new int[size];
  std::srand(std::time(nullptr));
  for (size_t i = 0; i < size; i++)
  {
    dynamic_arr[i] = std::rand();
  }
  return dynamic_arr;
}
