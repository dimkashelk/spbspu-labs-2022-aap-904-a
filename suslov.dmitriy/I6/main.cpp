#include <iostream>
#include <cmath>
#include "taylor.h"
int main()
{
  double absError = 0.01;
  int numberMax = 150;
  double start = -0.85,
    end = 0.85,
    step = 0.1;
  for (double i = start; i <= end; i += step)
  {
    std::cout << i << " : "
              << (1 / pow(1 + i, 3))
              << " : " << printTable(i, absError, numberMax) << std::endl;
  }
  return 0;
}
