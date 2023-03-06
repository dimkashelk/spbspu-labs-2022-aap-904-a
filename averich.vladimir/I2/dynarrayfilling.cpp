#include "dynarrayfilling.hpp"
#include <cstdlib>
#include <cstddef>
int* dynArrayFilling(int* dynArray, size_t sizeOfDynArray)
{
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + std::rand() % 9;
  }
  return dynArray;
}
