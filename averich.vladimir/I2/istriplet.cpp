#include "istriplet.hpp"
#include <cstddef>
#include <stdexcept>
int isTriplet(const int arr[], size_t size)
{
  if (size < 3)
  {
    throw std::length_error("Error triplet");
  }
  int countOfTriplet = 0;
  for (size_t i = 2; i < size; i++)
  {
    if (arr[i] < arr[i - 1])
    {
      if (arr[i - 1] < arr[i - 2])
      {
        countOfTriplet += 1;
      }
    }
  }
  return countOfTriplet;
}
