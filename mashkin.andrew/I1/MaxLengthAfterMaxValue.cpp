#include "MaxLengthAfterMaxValue.h"

void maxLengthAfterMaxValue(int& value, int& maxValue, unsigned int& count, unsigned int& maxCount)
{
  if (value >= maxValue)
  {
    maxValue = value;
    maxCount = count < maxCount ? maxCount : count;
    count = 0;
  }
  else
  {
    count++;
    maxCount = count < maxCount ? maxCount : count;
  }
}
