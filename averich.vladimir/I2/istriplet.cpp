#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(int arr[], size_t size)
{
  if (size < 3)
  {
    throw std::length_error("Error triplet");
  }
  size_t i = 0;
  int countOfTriplet = 0;
  while (i != size)
  {
    size_t j = 1;
    size_t k = 2;
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
