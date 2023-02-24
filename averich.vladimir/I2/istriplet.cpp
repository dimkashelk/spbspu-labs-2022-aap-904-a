#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(int arr[], size_t size)
{
  if (size < 3)
  {
    throw std::length_error("Error");
  }
  size_t i = 0;
  size_t j = 1;
  size_t k = 2;
  int countOfTriplet = 0;
  while (k != size)
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
