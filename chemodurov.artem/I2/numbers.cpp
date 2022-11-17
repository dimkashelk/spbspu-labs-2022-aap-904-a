#include "numbers.h"

unsigned int chemodurov::countMaxDecreasing(int * arr, size_t size)
{
  unsigned int dec_cnt = 1;
  unsigned int max_dec_cnt = 1;
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

unsigned int chemodurov::countDivisible(int * arr, size_t size, int divider)
{
  unsigned int divisible_cnt = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (arr[i] % divider == 0)
    {
      divisible_cnt += 1;
    }
  }
  return divisible_cnt;
}
