#include <iostream>
#include "MaxLengthAfterMaxValue.h"
#include "MaxLengthDescSeq.h"

int main()
{
  int value = 0;
  int maxValue = std::numeric_limits<int>::min();
  std::cin >> value;
  int predValue = value;
  unsigned int count = 0;
  unsigned int maxCount = 0;
  unsigned int length = 1;
  unsigned int maxlength = 1;
  do
  {
    maxLengthAfterMaxValue(value, maxValue, count, maxCount);
    maxLengthDescSeq(value, predValue, length, maxlength);
    std::cin >> value;
  } while (value && std::cin);
  std::cout << maxlength << "\n" << maxCount;
}
