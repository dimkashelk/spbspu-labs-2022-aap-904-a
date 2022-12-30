#ifndef CALCEEXPNEGATIVEXEXP2_HPP
#define CALCEEXPNEGATIVEXEXP2_HPP

#include <cstddef>

class TaylorNextTerm
{
public:
  explicit TaylorNextTerm(double x);
  double operator()();

private:
  double x;
  unsigned int factorial_of;
  unsigned int exp;
  size_t terms_count;
};

double countFraction(double x, unsigned int &factorial_of, unsigned int &exp);
double сalcEExpNegativeXExp2(double x, double abs_error, size_t number_max);

#endif
