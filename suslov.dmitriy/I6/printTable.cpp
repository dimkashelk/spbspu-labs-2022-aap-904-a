#include <iostream>
#include <cmath>
#include "printTable.h"
double printTable(double x, double absError, int numberMax)
{
  if (x <= -1 || x >= 1)
  {
    throw std::invalid_argument("x is invalid");
  }
  double sign = -1;
  double xInPow = 1, result = 0;
  bool flag = false;
  for (int i = 0; i < numberMax; i++)
  {
    sign *= -1;
    int con = (i + 1) * (i + 2) / 2;
    double addend = sign * con * xInPow;
    if (abs(addend) < absError)
    {
      flag = true;
      break;
    }
    result += addend;
    xInPow *= x;
  }
  if (!flag)
  {
    throw std::invalid_argument("invalid numberMax");
  }
  return result;
}
