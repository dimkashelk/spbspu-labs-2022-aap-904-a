#include <iostream>
#include "printTable.h"
int main()
{
  double a = 0;
  std::cin >> a;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  printTable(std::cout, a);
}
