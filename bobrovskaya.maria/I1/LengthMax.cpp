#include "LengthMax.h"
#include <iostream>

void LengthMax::operator()(int value, int predV)
{
  if (predV > value)
  {
    count++;
    if (count > length_max)
    {
      length_max = count;
    }
  }
  else
  {
    count = 1;
  }
}
