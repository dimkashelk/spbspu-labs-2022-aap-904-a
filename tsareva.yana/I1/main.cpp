#include "countersumprev.h"
#include "counterlocalmaximum.h"
#include <iostream>
int main()
{
  int n = 0;
  std::cin >> n;
  CounterLocalMaximum counterLocalMaximum(n);
  CounterSumPrev counterSumPrev(n);
  while (n && std::cin)
  {
    if (std::cin)
    {
      try
      {
        counterLocalMaximum(n);
        counterSumPrev(n);
      }
      catch (const std::overflow_error &e)
      {
        std::cout << e.what();
        return 2;
      }
    }
    std::cin >> n;
  }
  if (!std::cin)
  {
    std::cout << "Error while input new numbers";
    return 1;
  }
  std::cout << counterSumPrev.get_count() << std::endl;
  std::cout << counterLocalMaximum.get_count() << std::endl;
  return 0;
}
