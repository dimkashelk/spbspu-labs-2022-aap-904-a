#include "countrows.h"
#include <iostream>
size_t countDiverseElements(const int * array, size_t rows, size_t columns)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
  	for (size_t j = 0; j < columns; j++)
    {
      bool foundSimilar = false;
      int currentEl = array[i*rows + j];
      for (size_t k = j + 1; k < columns; k++)
      {
        if (currentEl == array[i*rows + k])
        {
          foundSimilar = true;
          break;
        }
      }
      count += foundSimilar;
    }
  }
  return count;
}
