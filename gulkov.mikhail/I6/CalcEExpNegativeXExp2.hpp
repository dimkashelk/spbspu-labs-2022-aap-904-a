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
  size_t terms_number;
  size_t numberMax;
};

double countFraction(double x, double factorial_of, unsigned int exp);

double countTerm(double terms_count, double x, double factorial_of, unsigned int exp);

#endif
