#include "generationdynarray.hpp"
#include <stdlib.h>
#include <cstddef>
int* generationDynArray(int* dynArray, size_t sizeOfDynArray)
{
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
  }
  return dynArray;
}
