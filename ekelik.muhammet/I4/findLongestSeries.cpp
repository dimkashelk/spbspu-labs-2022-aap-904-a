#include "findLongestSeries.h"

size_t findLongestSeries(int* matrix, size_t rows, size_t cols)
{
  size_t maxSeriesLength = 1;
  size_t currentSeriesLength = 1;
  size_t maxSeriesRow = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols - 1; j++)
    {
      if (matrix[i*cols + j] == matrix[i*cols + j + 1])
      {
        currentSeriesLength++;
        if (currentSeriesLength > maxSeriesLength)
        {
          maxSeriesLength = currentSeriesLength;
          maxSeriesRow = i;
        }
      }
      else
      {
        currentSeriesLength = 1;
      }
    }
    currentSeriesLength = 1;
  }
  return maxSeriesRow;
}
