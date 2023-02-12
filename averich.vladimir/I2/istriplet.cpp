#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(int arr[], size_t size)
{
  size_t i = 0;
  size_t j = 1;
  size_t k = 2;
  if (size < 3)
  {
   std::cout << "Error: can't find the triplet, because the array has less than three elements " << std::endl;
   return 1;
  }
  else if (size == 0)
  {
   std::cout << "Error: invalid size of array" << std::endl;
   return 1;
  }
  else
  {
   int countOfTriplet = 0;
   for (size_t l = 0; l < size - 2; l++)
   {
    if (arr[i] > arr[j] && arr[j] > arr[k])
    {
     countOfTriplet += 1;
    }
    i++;
    j++;
    k++;
   }
   return countOfTriplet;
  }
  return 0;
}
