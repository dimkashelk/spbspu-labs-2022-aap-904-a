#include <iostream>
#include "sumcount.hpp"
int main()
{
  unsigned int value = 0;
  unsigned int prevalue = 0;
  unsigned int preprevalue = 0;
  int countersum = 0;
  int countermod = 0;
  std::cin >> value;
  if (!std::cin)
  {
   std::cout << "Error, you need to type an integer\n";
   return 1;
  }
  while (value != 0)
  {
    preprevalue = prevalue;
    prevalue = value;
    std::cin >> value;
    if (!std::cin)
    {
     std::cout << "Entered incorrect value\n";
     return 1;
    }
    countersum += countIsSum(preprevalue, prevalue, value);
    std::cout << "Count of sum: " << countersum << "\n";
  }
  return 0;
}