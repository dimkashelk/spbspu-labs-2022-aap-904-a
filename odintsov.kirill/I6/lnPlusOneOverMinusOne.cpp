#include "lnPlusOneOverMinusOne.hpp"
#include <stdexcept>

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
  if ((x <= 2.0) || (x >= 3.0)) {
    throw std::invalid_argument("x is set incorrectly");
  }
  double result = 0.0;
  LnTermGenerator generateTerm(x);
  double term = 0.0;
  for (unsigned i = 0; i < numberMax; i++) {
    term = generateTerm(); 
    if (term < absError) {
      break;
    }
    result += term;
  }
  if (term > absError) {
    throw std::runtime_error("absolute error not achieved");
  }
  return result * 2;
}
