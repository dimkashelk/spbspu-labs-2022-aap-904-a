#include "counters.h"
#include <iostream>
int main()
{
  CounterMoreNext counterMoreNext{0, 0};
  CounterDecreasing counterDecreasing{0, 0, 0};
  int n;
  std::cin >> n;
  while (n && std::cin)
  {
    try
    {
      counterMoreNext(n);
      counterDecreasing(n);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << std::endl;
      return 2;
    }
    std::cin >> n;
  }
  if (!std::cin)
  {
    std::cout << "Error" << std::endl;
    return 1;
  }
  return 0;
}

