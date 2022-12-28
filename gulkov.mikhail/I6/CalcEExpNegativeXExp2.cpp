#include "CalcEExpNegativeXExp2.hpp"

CalcEExpNegativeXExp2::CalcEExpNegativeXExp2(double x, double absError, size_t numberMax) : x(x), absError(absError),
                                                                                            terms_number(0), numberMax(numberMax)
{}

double CalcEExpNegativeXExp2::operator()()
{
  terms_number = 0;
  double result = 0;

  return result;
}

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

double countTerm(double terms_count, double x, double factorial_of, unsigned int exp)
{
  if (terms_count == 0)
  {
    return 1;
  }
  else if (terms_count == 1)
  {
    return (x * x);
  }
  else
  {
    return countFraction(x, factorial_of, exp);
  }
}
