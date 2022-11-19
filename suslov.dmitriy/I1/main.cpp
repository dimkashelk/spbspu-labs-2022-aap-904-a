#include "countermorethanprevious.h"
#include "maxlendescendingfragment.h"
#include <iostream>
int main()
{
  int next = 0;
  std::cin >> next;
  CounterMoreThanPrevious counterMoreThanPrevious(next);
  MaxLenDescendingFragment maxLenDescendingFragment(next);
  while (next && std::cin)
  {
    if (std::cin)
    {
      try
      {
        counterMoreThanPrevious(next);
        maxLenDescendingFragment(next);
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
    std::cout << "bruh..." << "\n";
    return 1;
  }
  std::cout << counterMoreThanPrevious.get_count() << "\n";
  std::cout << maxLenDescendingFragment.get_length() << "\n";
}
