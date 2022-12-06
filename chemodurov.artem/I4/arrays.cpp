#include "arrays.h"
size_t chemodurov:: countGrowingRows(int * arr, size_t rows, size_t cols)
{
  size_t counter = 0;
  size_t number_of_item = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    sie_t counter_in_row = 0;
    for (size_t j = 0; j < cols - 1; ++j)
    {
      number_of_item = i * cols + j;
      if (arr[number_of_item] > arr[number_of_item + 1])
      {
        counter_in_row++;
      }
    }
    if (counter_in_row == cols - 1)
    {
      counter++;
    }
  }
  return counter;
}
