#ifndef CALCEEXPNEGATIVEXEXP2_HPP
#define CALCEEXPNEGATIVEXEXP2_HPP

#include <cstddef>

class CalcEExpNegativeXExp2
{
public:
  explicit CalcEExpNegativeXExp2(double x, size_t number_max);

  double operator()();

private:
  double x;
  double result;
  unsigned int factorial_of;
  unsigned int exp;
  size_t terms_count;
  size_t number_max;

  static double countFraction(double x, unsigned int &factorial_of, unsigned int &exp);

  static double countTerm(size_t terms_count, double x, unsigned int &factorial_of, unsigned int &exp);
};

#endif
