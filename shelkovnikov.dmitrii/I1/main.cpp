#include "counterelementslargerneighbors.h"
#include "counteraftermaximum.h"
#include <iostream>
int main()
{
  int next = 0;
  std::cin >> next;
  CounterElementsLargerNeighbors countElementsLargerNeighbors(next);
  CounterAfterMaximum counterAfterMaximum(next);
  while (next && std::cin)
  {
    if (std::cin)
    {
      try
      {
        countElementsLargerNeighbors(next);
        counterAfterMaximum(next);
      }
      catch (const std::overflow_error &e)
      {
        std::cout << e.what();
        return 2;
      }
    }
    std::cin >> next;
  }
  if (!std::cin)
  {
    std::cout << "Error... =(";
    return 1;
  }
  std::cout << countElementsLargerNeighbors.get_count() << std::endl;
  std::cout << counterAfterMaximum.get_count() << std::endl;
  return 0;
}
