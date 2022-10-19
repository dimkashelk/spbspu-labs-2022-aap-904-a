#include "compute.h"
#include <iostream>

int main()
{
  int current = 0;
  std::cin >> current;
  if (!std::cin)
  {
    std::cout << "incorrect data\n";
    return 0;
  }
  int last = current;
  int currentAmount = turkin::condition(current);
  int maxAmount = currentAmount;
  while (current != 0 && std::cin)
  {
    std::cin >> current;
    currentAmount = turkin::condition(last, current, currentAmount);
    maxAmount = turkin::max(maxAmount, currentAmount);
    last = current;
  }
  if (!std::cin)
  {
    std::cout << "incorrect data\n";
    return 0;
  }
  std::cout << maxAmount << std::endl;
  return 0;
}

