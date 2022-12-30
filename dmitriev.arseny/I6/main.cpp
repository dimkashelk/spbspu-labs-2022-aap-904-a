#include "defineArcSin.h"
#include <iostream>

int main()
{
  unsigned numberMax = 0;
  const double absError = 0.000001;
  double testX = 0.3;

  if (!std::cin)
  {
    std::cout << "incorrect input" << '\n';
    return 1;
  }

  try
  {
    std::cout << defineArcSin(testX, absError, numberMax) << '\n';
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }


  return 0;
}
