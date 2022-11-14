#include "repeatedNums.h"
#include <cstddef>
#include <stdexcept>

bool turkin::RepeatedNums::operator()(const int * array, size_t size, int begin, int end)
{
  if (begin < 0 || end >= size)
  {
    throw std::invalid_argument("invalid range");
  }
  size_t amount = 0;
  for (size_t i = begin; i < end; i++)
  {
    amount = 0;
    for (size_t j = begin; j < end; j++)
    {
      if (array[i] == array[j])
      {
        amount++;
      }
    }
    if (amount > 1)
    {
      return true;
    }
  }
  return false;
}

