#include <cstddef>
#include <limits>
#include <iostream>
#include <algorithm>
#include "onedimensionalarrays.h"
size_t countNegativeRightFromMax(const int *array, const size_t size)
{
  size_t countNegativeRightFromMax = 0;
  int maxElIndex = -1;
  int maxEl = -1 * std::numeric_limits<unsigned int>::max();
  std::cout << "---" << std::endl;
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i < size; i++)
  {
    if (array[i] > maxEl)
    {
      std::cout << "maxEl: " << maxEl << " maxElIndex: " << maxElIndex << std::endl;
      maxEl = array[i];
      maxElIndex = i;
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (i > maxElIndex)
    {
      if (array[i] < 0)
      {
        countNegativeRightFromMax++;
      }
    }
  }
  return countNegativeRightFromMax;
}
const char *countRepetitiveInRange(const int *array, const size_t size, const size_t beginIndex, const size_t endIndex)
{
  if (beginIndex >= endIndex || endIndex > size || beginIndex > size)
  {
    std::cerr << "Incorrect indexes." << std::endl;
    return "Error";
  }
  else
  {
    bool containsDuplicates = false;
    for (size_t i = beginIndex; i <= endIndex; i++)
    {
      for (size_t j = i + 1; j <= endIndex; j++)
      {
        if (array[i] == array[j])
        {
          containsDuplicates = true;
        }
      }
    }
    return containsDuplicates ? "True" : "False";
  }
}