#include "lnPlusOneOverMinusOne.hpp"

struct LnTermGenerator {
  double oneOverXSquared;
  double term;
  unsigned number;

  explicit LnTermGenerator(double x):
    oneOverXSquared(1 / (x * x)),
    term(1 / x),
    number(0)
  {}

  double operator()()
  {
    if (number == 0) {
      number++;
      return term;
    }
    term *= (number++) * 2 - 1;
    term *= oneOverXSquared;
    term /= number * 2 - 1;
    return term;
  }
};

double odintsov::lnPlusOneOverMinusOne(double x, double absError, unsigned numberMax)
{
  return 0.0;
}
