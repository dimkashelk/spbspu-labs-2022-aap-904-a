#include "shenanigans.h"

int main()
{
  const double error = 0.0001;
  const double step = 0.01;
  double lb = 0;
  double rb = 0;
  size_t maxNum = 0;

  std::cin >> lb >> rb >> maxNum;

  printTable(std::cout, lb, rb, error, maxNum, step);
}