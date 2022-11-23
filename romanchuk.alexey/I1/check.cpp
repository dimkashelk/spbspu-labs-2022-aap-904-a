#include <iostream>
#include <limits>
#include "structure.h"

void values::operator()(int value)
{
  const int maxValue = std::numeric_limits< int >::max();
  if (maxNum == maxValue)
  {
  std::cout << "overflow";
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
  }

  if (pp_value && value) {
  if (p_value > pp_value && p_value > value) {
  count++;
  }
  }
  pp_value = p_value;
  p_value = value;
}
