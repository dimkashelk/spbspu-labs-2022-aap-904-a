#include "counter.h"
#include <iostream>
int main()
{
  int next = 0;
  std::cin >> next;
  Counter countElementsLargerNeighbors(next, next);
  while (next && std::cin)
  {
    if (std::cin)
    {
      try
      {
        countElementsLargerNeighbors(next);
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
  return 0;
}
