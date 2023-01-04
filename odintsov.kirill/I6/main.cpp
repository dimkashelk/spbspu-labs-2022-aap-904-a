#include <iostream>
#include <exception>
#include "lnPlusOneOverMinusOne.hpp"

int main()
{
  double absError = 0.01;
  unsigned numberMax = 3;
  double l = 2.1;
  double r = 2.9;
  double step = 0.1;
  std::cin >> absError >> numberMax >> l >> r >> step;
  if (!std::cin) {
    std::cout << "Error: Input error";
    return 1;
  }
  try {
    odintsov::outputComparisonTable(std::cout, l, r, step, absError, numberMax) << '\n';
  } catch (const std::exception& err) {
    std::cout << err.what() << '\n';
    return 1;
  }
}
