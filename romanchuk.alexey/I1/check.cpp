#include "sequences.h"
#include <iostream>
#include <limits>

void values::operator()(int value)
{
  constexpr int maxValue = std::numeric_limits< int >::max();
  if (maxNum == maxValue)
  {
    std::cout << "overflow";
    return;
  }
  else if (value == predV)
  {
    nValue += 1;
  }
  else
  {
    maxNum = std::max(nValue, maxNum);
    nValue = 1;
  }
  predV = value;
}
void localValuesMax::operator()(int value)
{
  constexpr int maxLocalVal = std::numeric_limits< int >::max();
  if (value == maxLocalVal)
  {
    std::cout << "overflow";
    return;
  }
  if (pp_value && value)
  {
    if (p_value > pp_value && p_value > value)
    {
      count++;
    }
  }
  pp_value = p_value;
  p_value = value;
}