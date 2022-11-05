#include "compute.h"
#include <iostream>

int turkin::LengthOfSequence::isSame(int last, int current)
{
  return (current == last && current != 0) ? ++currentAmount : 0;
}

void turkin::LengthOfSequence::updateAmount(int last, int current)
{
  currentAmount = turkin::LengthOfSequence::isSame(last, current);
  maxAmount = std::max(maxAmount, currentAmount);
  count++;
}

int turkin::LengthOfSequence::getMaxAmount()
{
  return maxAmount + ((count > 1) ? 1 : 0);
}

void turkin::PreMaximum::updatePreMaximum(int current)
{
  if (beforeMax < current)
  {
    if (current > allMax)
    {
      beforeMax = allMax;
      allMax = current;
    }
    else
    {
      beforeMax = current;
    }
  }
}

int turkin::PreMaximum::getPreMaximum()
{
  return beforeMax;
}

