#include "counter.h"
#include <iostream>
int main()
{
  int next = 0;
  std::cin >> next;
  Counter counter(next, next);
  while (next && std::cin)
  {
    if (std::cin)
    {
      try
      {
        counter(next);
      }
      catch (std::overflow_error &e)
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
  std::cout << counter.get_count() << std::endl;
  return 0;
}
