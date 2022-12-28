#include "CalcEExpNegativeXExp2.hpp"

CalcEExpNegativeXExp2::CalcEExpNegativeXExp2(double x, double absError, size_t numberMax) : x(x), absError(absError), result(0),
                                                                                            factorial_of(2), exp(0),
                                                                                            terms_count(0), numberMax(numberMax)
{}

double CalcEExpNegativeXExp2::operator()()
{

  return result;
}

double countFraction(double x, unsigned int &factorial_of, unsigned int exp)
{
  int factorial = 0;
  for (unsigned int i = 0; i < exp; ++i)
  {
    x *= x;
  }
  for (unsigned int i = 0; i < factorial_of; ++i)
  {
    factorial *= i;
  }
  ++factorial;
  return (x / factorial);
}

double countTerm(double terms_count, double x, unsigned int &factorial_of, unsigned int exp)
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
