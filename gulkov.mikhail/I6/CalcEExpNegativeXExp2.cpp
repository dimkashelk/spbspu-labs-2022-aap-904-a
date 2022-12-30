#include "CalcEExpNegativeXExp2.hpp"
#include <cmath>

CalcEExpNegativeXExp2::CalcEExpNegativeXExp2(double x, size_t number_max, double abs_error) : x(x), result(0),
                                                                                              abs_error(abs_error),
                                                                                              factorial_of(2), exp(3),
                                                                                              terms_count(0),
                                                                                              number_max(number_max)
{}

double CalcEExpNegativeXExp2::operator()()
{
  double member = 0;
  do
  {
    result += member;

    member = terms_count % 2 == 0 ? this->countTerm(terms_count, x, factorial_of, exp) : (-1 * this
      ->countTerm(terms_count, x, factorial_of, exp));
    terms_count++;
  }
  while (std::abs(member) > abs_error && terms_count < number_max);

  terms_count = 0;
  return result;
}

double CalcEExpNegativeXExp2::countFraction(double x, unsigned int &factorial_of, unsigned int &exp)
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

double CalcEExpNegativeXExp2::countTerm(size_t terms_count, double x, unsigned int &factorial_of, unsigned int &exp)
{
  if (terms_count == 0)
  {
    return (1);
  }
  else if (terms_count == 1)
  {
    return (x * x);
  }
  else
  {
    return CalcEExpNegativeXExp2::countFraction(x, factorial_of, exp);
  }
}
