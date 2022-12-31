#include <stdexcept>
#include "defineArcSin.h"

double defineArcSin(double x, double absError, unsigned numberMax)
{
  if (x * x > 1)
  {
    throw std::logic_error("x does not fall within the specified interval");
  }
  MemberOfRow defineNewMember(x);
  double result = x;
  double member = 0.0;

  for (unsigned n = 0; n < numberMax; n++)
  {
    result = result + member;
    member = defineNewMember();
    if (member < absError)
    {
      return result;
    }
  }

  throw std::logic_error("the required accuracy has not been achieved");
}

MemberOfRow::MemberOfRow(double x)
{
  this->x = x;
  powX = x;

  even = 1;
  odd = 2;
  factorialEven = 1;
  factorialOdd = 1;
}

double MemberOfRow::operator()()
{
  powX = powX * x * x;
  even = even + 2;
  factorialOdd = factorialOdd * odd;

  double member = 0;
  member = (factorialEven * powX) / (double(factorialOdd) * even);

  odd = odd + 2;
  factorialEven = factorialEven * even;

  return member;
}
