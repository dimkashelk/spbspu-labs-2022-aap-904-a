#include "arithmetic_mean_of_array.h"

double countArithmeticMean (const int *array, size_t N)
{
  int sum = 0;
  double arithmetic_mean = 0.0;
  for (size_t i = 0; i < N; i++)
  {
    sum += array[i];
  }
  arithmetic_mean = static_cast< double >(sum) / N;
  return arithmetic_mean;
}
