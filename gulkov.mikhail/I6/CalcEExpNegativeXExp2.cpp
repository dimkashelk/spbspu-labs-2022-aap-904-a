#include "CalcEExpNegativeXExp2.hpp"
#include <cmath>

TaylorNextTerm::TaylorNextTerm(double x):
  x(x),
  factorial_of(2),
  exp(3),
  terms_count(0)
{}

double TaylorNextTerm::operator()()
{
  double fraction = 0;
  if (terms_count == 0)
  {
    terms_count++;
    return (1);
  }
  else if (terms_count == 1)
  {
    terms_count++;
    return (-1 * (x * x));
  }
  else
  {
    fraction = countFraction(x, factorial_of, exp);
    terms_count++;
    return terms_count % 2 != 0 ? fraction : (-1 * fraction);
  }
}

double countFraction(double x, unsigned int &factorial_of, unsigned int &exp)
{
  double counted_exp_x = x;
  int factorial = 1;
  for (unsigned int i = 0; i < exp; i++)
  {
    counted_exp_x *= x;
  }
  for (unsigned int i = 1; i <= factorial_of; i++)
  {
    factorial *= static_cast< int >(i);
  }
  exp += 2;
  factorial_of++;
  return (counted_exp_x / factorial);
}

double сalcEExpNegativeXExp2(double x, double abs_error, size_t number_max)
{
  TaylorNextTerm TaylorNextTerm(x);
  double member = 0;
  double result = 0;
  unsigned counter = 0;
  do
  {
    member = TaylorNextTerm();
    result += member;
    counter++;
  }
  while (std::abs(member) > abs_error && counter < number_max);

  return result;
}
