#include <cstddef>
#include <limits>
#include <iostream>
#include <algorithm>
#include "oneDimensionalArrays.h"
size_t countNegativeRightFromMax(const int *array, const size_t size)
{
  size_t countNegativeRightFromMax = 0;
  int maxElIndex = -1;
  int maxEl = -1 * std::numeric_limits<unsigned int>::max();
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] > maxEl)
    {
      maxEl = array[i];
      maxElIndex = static_cast<int>(i);
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    if (static_cast<int>(i) > maxElIndex)
    {
      if (array[i] < 0)
      {
        countNegativeRightFromMax++;
      }
    }
  }
  return countNegativeRightFromMax;
}
size_t countRepetitiveInRange(const int *array, const size_t size, const size_t beginIndex, const size_t endIndex)
{
  if (beginIndex >= endIndex || endIndex > size || beginIndex > size)
  {
    return 0;
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
    return containsDuplicates;
  }
}
