#include "divSinXOnX.h"
#include <stdexcept>

double divSinXOnX(double x, double absError, size_t numberMax)
{
  if (x * x > 1)
  {
    throw std::logic_error("X is more than board of values");
  }
  DivisionSinXOnX newMembOfRow(x);
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

DivisionSinXOnX::DivisionSinXOnX(double x):
  x_(x),
  powX_(1),
  factorial_(1),
  var_(1),
  sign_(0)
{}

double DivisionSinXOnX::operator()()
{
  double memb = sign_ % 2 ? -(powX_ / factorial_) : powX_ / factorial_;
  sign_ += 1;
  powX_ *= (x_ * x_);
  var_ += 2;
  factorial_ *= (var_ * (var_ - 1));
  return memb;
}
