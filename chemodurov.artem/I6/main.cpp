#include <iostream>
#include "sqrt1minusxsquare.h"

int main()
{
  double left = 0.0d;
  double right = 0.0d;
  size_t max_members = 0;
  const double max_right = 1.0d;
  const double min_left = -1.0d;
  std::cin >> left >> right >> max_members;
  if (!std::cin || right < left || right >= max_right || left <= min_left || !max_members)
  {
    std::cerr << "Error, check parameters\n";
    return 1;
  }
//  const double error = 0.00001d;
//  const double step = 0.05d;
  return 0;
}
