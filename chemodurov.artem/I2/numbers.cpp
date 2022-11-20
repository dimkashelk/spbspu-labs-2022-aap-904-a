#include "numbers.h"

size_t chemodurov::countMaxDecreasing(const int * arr, const size_t size)
{
  size_t dec_cnt = 1;
  size_t max_dec_cnt = 1;
  for (size_t i = 0; i < size - 1; ++i)
  {
    if (arr[i] > arr[i + 1])
    {
      dec_cnt += 1;
      if (max_dec_cnt < dec_cnt)
      {
        max_dec_cnt = dec_cnt;
      }
    }
    else
    {
      dec_cnt = 1;
    }
  }
  return max_dec_cnt;
}

size_t chemodurov::countDivisible(const int * arr, const size_t size, const int divider)
{
  size_t divisible_cnt = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (arr[i] % divider == 0)
    {
      divisible_cnt += 1;
    }
  }
  return divisible_cnt;
}
