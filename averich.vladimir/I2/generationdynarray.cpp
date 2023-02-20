#include "generationdynarray.hpp"
#include <iostream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
int* generationDynArray(size_t sizeOfDynArray)
{
  int* dynArray = new int[sizeOfDynArray];
  std::srand(time(nullptr));
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
    dynArray[i] = 1 + rand() % 9 * -1;
  }
  return dynArray;
}
