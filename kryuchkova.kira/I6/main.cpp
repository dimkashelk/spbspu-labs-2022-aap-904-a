#include <iostream>
#include <cstddef>

int main()
{
  size_t max_number = 0;
  double left = 0.0;
  double right = 0.0;
  const double step = 0.01;
  const double error = 0.0001;
  std::cin >> left >> right >> max_number;

  if (!std::cin || left < -1.0 || right > 1.0 || left > right)
  {
    std::cerr << "invalid input" << '\n';
    return 1;
  }

}
