#include "MaxLengthDescSeq.h"

void maxLengthDescSeq(int& value, int& predValue, unsigned int& length, unsigned int& maxLength)
{
  if (predValue > value)
  {
    length++;
    maxLength = maxLength < length ? length : maxLength;
  }
  else
  {
    maxLength = maxLength < length ? length : maxLength;
    length = 1;
  }
  predValue = value;
}
