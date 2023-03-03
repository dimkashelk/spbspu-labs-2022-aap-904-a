#include "istriplet.hpp"
#include <iostream>
#include <cstddef>
int isTriplet(const int arr[], size_t size)
{
  if (size < 3)
  {
    throw std::length_error("Error triplet");
  }
  int countOfTriplet = 0;
  for (size_t i = 0; i != size; i++)
  {
    if (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2])
    {
      countOfTriplet += 1;
    }
  }
  return countOfTriplet;
}
