#include "max_sum_diag.h"

int maxSumDiag(int* arr, int size_of_dyn_array)
{
  int max_sum = 0;
  for (int i = 0; i < size_of_dyn_array; ++i)
  {
    int row = 0;
    int col = i;
    int sum1 = 0;
    int sum2 = 0;
    while ((col < size_of_dyn_array) && (row < size_of_dyn_array))
    {
      sum1 += arr[row][col];
      sum2 += arr[col][row];
      row++;
      col++;
    }
    if (sum1 > max_sum)
    {
      max_sum = sum1;
    }
    if (sum2 > max_sum)
    {
      max_sum = sum2;
    }
  }
  return max_sum;
}
