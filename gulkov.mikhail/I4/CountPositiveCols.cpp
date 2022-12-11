#include "CountPositiveCols.hpp"

unsigned int count_positive_cols(int *array, unsigned int cols)
{

  unsigned int positive_cols = 0;

  for (unsigned int i = 0; i < cols; i++)
  {
    if (array[i] > 0 && array[i + 3] > 0 && array[i + 6] > 0)
    {
      positive_cols++;
    }
  }

  return positive_cols;
}
