#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(const int arr[], size_t size)
{
  if (size < 3)
  {
    throw std::length_error("Error triplet");
  }
  size_t i = 0;
  int countOfTriplet = 0;
  while (i != size)
  {
    if (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2])
    {
      countOfTriplet += 1;
    }
    i++;
  }
  return countOfTriplet;
}
