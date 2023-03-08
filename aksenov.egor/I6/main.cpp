#include <iostream>
#include "printTable.h"
int main()
{
  const double step = 0.1;
  const double absError = 0.00001;
  double l = 0.0;
  double r = 0.0;
  unsigned numberMax = 0;
  std::cin >> l >> r >> numberMax;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  printTable(std::cout, l, r, step, absError, numberMax);
  return 0;
}
