#include "CalcEExpNegativeXExp2.hpp"
#include <iostream>
#include <cstddef>

int main()
{
  size_t number_max = 0;
  double lhs = 0.0;
  double rhs = 0.0;
  const double step = 0.01;
  const double error = 0.0001;
  std::cin >> lhs >> rhs >> number_max;

  if (!std::cin || lhs < -1.0 || rhs > 1.0 || lhs > rhs)
  {
    std::cerr << "Error: incorrect input\n";
    return 1;
  }
}
