#include "generationdynarray.hpp"
#include <iostream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
int generationDynArray(size_t sizeOfDynArray)
{
  if (sizeOfDynArray == 0)
  {
   std::cout << "Error: invalid size of array" << std::endl;
   return 1;
  }
  else
  {
   int * dynArray = new int[sizeOfDynArray];
   std::srand(time(nullptr));
   for (size_t i = 0; i < sizeOfDynArray; i++)
   {
     dynArray[i] = 1 + rand() % 9;
     dynArray[i] = 1 + rand() % 9 * -1;
   }
   std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << std::endl;
   sort(dynArray, sizeOfDynArray);
   delete[] dynArray;
   return 0;
  }
  return 0;
}
