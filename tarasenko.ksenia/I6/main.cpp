#include <iostream>

int main()
{
  double rightBorder, leftBorder = 0;
  unsigned numberMax = 0;
  const double step = 0.2d;
  const double absError = 0.00001d;
  std::cin >> numberMax >> rightBorder >> leftBorder;
  if (!std::cin)
  {
    std::cout << "Error";
    return 1;
  }
}
