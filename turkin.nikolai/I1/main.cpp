#include "compute.h"
#include <iostream>

int main()
{
  int current = 1;
  int last = 0;
  turkin::LengthOfSequence len;
  turkin::PreMaximum max;

  while (current && std::cin)
  {
    std::cin >> current;
    len.updateAmount(last, current);
    max.updatePreMaximum(current);
    last = current;
  }

  if (!std::cin)
  {
    std::cout << "incorrect data\n";
    return 0;
  }
  std::cout << "MaxAmount: " << len.getMaxAmount() << "\tBeforeMax: " << max.getPreMaximum() << std::endl;
  return 0;
}
