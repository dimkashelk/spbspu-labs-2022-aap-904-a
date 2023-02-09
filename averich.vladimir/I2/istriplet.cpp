#include "istriplet.hpp"
#include <iostream>
int isTriplet(int arr[], int size)
{
  if (size < 0)
  {
    std::cout << "Error: size of array is wrong, try again";
  }
  int i = 0;
  int j = 1;
  int k = 2;
  int countOfTriplet = 0;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > arr[j] > arr[k])
    {
  	  countOfTriplet += 1;
    }
    i++;
    j++;
    k++;
  }
  std::cout << "Count of triplets: " << countOfTriplet << " ";
  return 0;
}
