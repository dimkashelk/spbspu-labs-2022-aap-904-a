#include "findLongestSeries.h"

int findLongestSeries(const int* matrix, size_t numRows, size_t numCols)
{
  int longestSeries = 1;
  int currentSeries = 1;
  for (size_t i = 0; i < numRows; i++)
  {
    for (size_t j = 1; j < numCols; j++)
    {
      if (matrix[numCols * i + j] == matrix[numCols * i + j - 1])
      {
        currentSeries++;
        if (currentSeries > longestSeries)
        {
          longestSeries = currentSeries;
        }
      }
      else
      {
        currentSeries = 1;
      }
    }
    currentSeries = 1;
  }
  return longestSeries;
}
