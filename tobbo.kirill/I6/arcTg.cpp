#include "arcTg.h"
#include <cmath>
#include <stdexcept>

double calcArcTg(double x, double absError, unsigned numberMax)
{
  MemberOfRow calcMember(x);
  double res = 0.0;
  double member = 0.0;
  unsigned count = 0;
  do
  {
    member = calcMember();
    res += member;
    count++;
  } while (std::abs(member) > absError && count < numberMax);

  if (std::abs(member) > absError || count >= numberMax)
  {
    throw std::invalid_argument("Accuracy is not achieved");
  }
  return res;
}

MemberOfRow::MemberOfRow(double x) :
  x(x),
  ittnum(0),
  sign(0)
{
  if (x < 2 || x > 3)
  {
    throw std::invalid_argument("Interval error");
  }
}

double MemberOfRow::operator()()
{
  if (ittnum == 0)
  {
    ittnum = 1;
    double pi = 3.14159265358979323846;
    return pi / 2;
  }
  double res = 1 / (ittnum * std::pow(x, ittnum));
  ittnum += 2;
  return res * (sign++ % 2 != 0 ? 1 : -1);
}
