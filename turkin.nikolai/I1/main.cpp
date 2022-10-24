#include "compute.h"
#include <iostream>

int main()
{
  int current = 1;
  int last = 0;
  int currentAmount = 0;
  int maxAmount = 0;
  int count = 0;
  int allMax = 0;
  int beforeMax = 0;
  turkin::CompareNums comparator;

  while (current && std::cin)
  {
    std::cin >> current;
    currentAmount = comparator(last, current, currentAmount);
    maxAmount = std::max(maxAmount, currentAmount);
    last = current;
    count++;

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

  if (!std::cin)
  {
    std::cout << "incorrect data\n";
    return 0;
  }
  maxAmount = maxAmount + ((count > 1) ? 1 : 0);
  std::cout << "MaxAmount: " << maxAmount << "\tBeforeMax: " << beforeMax << std::endl;
  return 0;
}

