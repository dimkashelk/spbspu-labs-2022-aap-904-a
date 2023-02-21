#include "divSinXOnX.h"
#include <stdexcept>

double divSinXOnX(double x, double absError, size_t numberMax)
{
  if (x * x > 1)
  {
    throw std::logic_error("X is more than board of values");
  }
  NewMemb newMembOfRow(x);
  double res = 0.0;
  double memb = 0.0;
  for (size_t i = 0; i < numberMax; i++)
  {
    memb = newMembOfRow();
    res += memb;
    if (absError > memb)
    {
      return res;
    }
  }
  throw std::logic_error("you have gone beyond the maximum number of terms");
}

NewMemb::NewMemb(double x) :
  x(x),
  powX(1),
  factorial(1),
  var(1),
  sign(0)
{}

double NewMemb::operator()()
{
  double memb = sign % 2 ? -(powX / factorial) : powX / factorial;
  sign += 1;
  powX *= (x * x);
  var += 2;
  factorial *= (var * (var - 1));
  return memb;
}
