#include "findExp.h"
#include <cmath>

double exp(double x, double error, unsigned int numberMax)
{
  double result = 1.0;
  double term = 1.0;
  double termError = 1.0;
  unsigned int n = 1;
  while (n < numberMax && termError > error)
  {
    term *= x / n;
    result += term;
    termError = fabs(term / result);
    n++;
  }
  return result;
}
