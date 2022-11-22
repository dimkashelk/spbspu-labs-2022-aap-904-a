#include "sequences.h"
#include <iostream> 

int main()
{
  int previous = 0;
  Localminimals count1{0};
  Minsrmax count2{0};
  do
  {
    std::cin >> previous;
    count1(previous, std::cin);
    count2(previous, std::cin);
  }
  while (previous && std::cin);
  if (!std::cin)
  {
    std::cout << "Not a number";
  }
  std::cout << count1.countlocalmin << '\n';
  std::cout << count2.countminsrmax << '\n';
}
