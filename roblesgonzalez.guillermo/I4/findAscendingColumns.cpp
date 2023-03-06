#include "findAscendingColumns.h"

bool isGrowingCol(const int *arr, size_t col, size_t rows, size_t cols)
{
  size_t counter_in_col = 0;
  for (size_t i = 0; i < rows - 1; ++i)
  {
    size_t number = i * cols + col;
    if (arr[number] < arr[number + cols])
    {
      counter_in_col++;
    }
  }
  return counter_in_col == rows - 1;
}
size_t countGrowingCols(const int *arr, size_t rows, size_t cols)
{
  const int *intArr = arr;
  size_t counter = 0;
  for (size_t i = 0; i < cols; ++i)
  {
    if (isGrowingCol(intArr, i, rows, cols))
    {
      counter++;
    }
    else
    {
      break;
    }
  }
  return counter;
}
