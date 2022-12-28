#include "CalcEExpNegativeXExp2.hpp"

double countFraction(double x, double factorial_of, unsigned int exp)
{
  int factorial = 0;
  for (unsigned int i = 0; i < exp; ++i)
  {
    x *= x;
  }
  for (int i = 0; i < factorial_of; ++i)
  {
    factorial *= i;
  }
  return (x / factorial);
}
