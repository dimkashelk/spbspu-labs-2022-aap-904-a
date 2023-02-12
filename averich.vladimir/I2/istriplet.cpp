#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(int arr[], size_t size)
{
  size_t i = 0;
  size_t j = 1;
  size_t k = 2;
  if (size < 3 || size == 0)
  {
   throw std::logic_error("Error: incorrect size of array");
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
