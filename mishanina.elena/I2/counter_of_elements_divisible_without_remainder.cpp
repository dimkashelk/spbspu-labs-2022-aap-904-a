#include <iostream>
#include "counter_of_elements_divisible_without_remainder.h"

size_t counter_of_elements_divisible_without_remainder(const int* array, size_t size, int cur_num)
{
  if (size == 0)
  {
    return 0;
  }
  if (cur_num == 0)
  {
    throw std::runtime_error("Attempted to divide by Zero\n");
  }
  int counter = 0;
  for (size_t i = 0;i < size;i++)
  {
   if (array[i] % cur_num == 0)
   {
     counter++;
   }
  }
  return counter;
}
