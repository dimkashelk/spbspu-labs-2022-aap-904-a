#ifndef CALCEEXPNEGATIVEXEXP2_HPP
#define CALCEEXPNEGATIVEXEXP2_HPP

#include <cstddef>

class CalcEExpNegativeXExp2
{
public:
  explicit CalcEExpNegativeXExp2(double x, double absError, size_t numberMax);

  double operator()();

private:
  double x;
  double absError;
  double result;
  unsigned int factorial_of;
  unsigned int exp;
  size_t terms_count;
  size_t numberMax;
};

double countFraction(double x, unsigned int &factorial_of, unsigned int &exp);

double countTerm(size_t terms_count, double x, unsigned int &factorial_of, unsigned int &exp);

#endif
