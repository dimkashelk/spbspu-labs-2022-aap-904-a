#include "generationdynarray.hpp"
#include <cstddef>
#include <iostream>
int* generationDynArray(int* dynArray, size_t sizeOfDynArray)
{
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
    dynArray[i] = 1 + rand() % 9 * -1;
  }
  return dynArray;
}
