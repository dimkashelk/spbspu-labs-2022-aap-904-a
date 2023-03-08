#include "coshinus.h"
#include <cmath>
double calculateCoshinus(double x, double absError, size_t numberMax)
{
  double sum = 1.0;
  double n = 0.0;
  unsigned factorial = 1;
  do
  {
    if (n == 0)
    {
      n += 1;
    }
    else
    {
      sum+= std::pow(x, 2 * n) / (2 * (factorial * n));
      n++;
    }
  }
  while (n != numberMax || n < absError);
  return sum;
}
