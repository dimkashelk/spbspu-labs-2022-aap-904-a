#include <iostream>
#include "sinh.h"
int main()
{
  double left = 0.0f, right = 0.0f;
  unsigned count = 0;
  std::cin >> left >> right >> count;
  if (!std::cin)
  {
    std::cout << "Error";
    return 1;
  }
  print_table(std::cout, left, right, 0.1, 0.02, count);
}
