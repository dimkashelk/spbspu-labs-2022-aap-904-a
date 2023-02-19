#include "generationdynarray.hpp"
#include <iostream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
int generationDynArray(size_t sizeOfDynArray)
{
  if (sizeOfDynArray == 0)
  {
    return 1;
  }
  int* dynArray = new int[sizeOfDynArray];
  std::srand(time(nullptr));
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
    dynArray[i] = 1 + rand() % 9 * -1;
  }
  try
  {
    std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << std::endl;
    sort(dynArray, sizeOfDynArray);
  }
  catch (const std::logic_error &e)
  {
    return 1;
  }
  delete[] dynArray;
  return 0;
}
